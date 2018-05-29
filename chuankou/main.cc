// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 1月  1 10:40:34 2017 (+0800)
// Last-Updated: 一 1月  2 16:35:32 2017 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 78
// URL: http://wuhongyi.cn 

#include <stdio.h>  /*标准输入输出定义*/
#include <stdlib.h> /*标准函数库定义*/
#include <unistd.h> /*Unix 标准函数定义*/
#include <sys/types.h> 
#include <sys/stat.h>   
#include <fcntl.h>  /*文件控制定义*/
#include <termios.h>/*POSIX 终端控制定义*/
#include <errno.h>  /*错误号定义*/

#include <ctime>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#define FALSE  -1
#define TRUE   0

/**
 *@brief  设置串口通信速率
 *@param  fd     类型 int  打开串口的文件句柄
 *@param  speed  类型 int  串口速度
 *@return  void
 */
int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,
		    B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400,  
		  19200,  9600, 4800, 2400, 1200,  300, };

void set_speed(int fd, int speed){
  int   i; 
  int   status; 
  struct termios   Opt;
  tcgetattr(fd, &Opt); 
  for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++) { 
    if  (speed == name_arr[i]) {     
      tcflush(fd, TCIOFLUSH);     
      cfsetispeed(&Opt, speed_arr[i]);  
      cfsetospeed(&Opt, speed_arr[i]);   
      status = tcsetattr(fd, TCSANOW, &Opt);  
      if  (status != 0) {        
	perror("tcsetattr fd");  
	return;     
      }    
      tcflush(fd,TCIOFLUSH);   
    }  
  }
}

/**
 *@brief   设置串口数据位，停止位和效验位
 *@param  fd     类型  int  打开的串口文件句柄
 *@param  databits 类型  int 数据位   取值 为 7 或者8
 *@param  stopbits 类型  int 停止位   取值为 1 或者2
 *@param  parity  类型  int  效验类型 取值为N,E,O,,S
 */
int set_Parity(int fd,int databits,int stopbits,int parity)
{ 
  struct termios options; 
  if  ( tcgetattr( fd,&options)  !=  0) { 
    perror("SetupSerial 1");     
    return(FALSE);  
  }
  options.c_cflag &= ~CSIZE; 
  switch (databits) /*设置数据位数*/
    {   
    case 7:        
      options.c_cflag |= CS7; 
      break;
    case 8:     
      options.c_cflag |= CS8;
      break;   
    default:    
      fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
    }
  switch (parity) 
    {   
    case 'n':
    case 'N':    
      options.c_cflag &= ~PARENB;   /* Clear parity enable */
      options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
      break;  
    case 'o':   
    case 'O':     
      options.c_cflag |= (PARODD | PARENB); /* 设置为奇效验*/  
      options.c_iflag |= INPCK;             /* Disnable parity checking */ 
      break;  
    case 'e':  
    case 'E':   
      options.c_cflag |= PARENB;     /* Enable parity */    
      options.c_cflag &= ~PARODD;   /* 转换为偶效验*/     
      options.c_iflag |= INPCK;       /* Disnable parity checking */
      break;
    case 'S': 
    case 's':  /*as no parity*/   
      options.c_cflag &= ~PARENB;
      options.c_cflag &= ~CSTOPB;break;  
    default:   
      fprintf(stderr,"Unsupported parity\n");    
      return (FALSE);  
    }  
  /* 设置停止位*/  
  switch (stopbits)
    {   
    case 1:    
      options.c_cflag &= ~CSTOPB;  
      break;  
    case 2:    
      options.c_cflag |= CSTOPB;  
      break;
    default:    
      fprintf(stderr,"Unsupported stop bits\n");  
      return (FALSE); 
    } 
  /* Set input parity option */ 
  if (parity != 'n')   
    options.c_iflag |= INPCK; 
  tcflush(fd,TCIFLUSH);

  options.c_iflag &= ~(IGNBRK | IGNCR | INLCR | ICRNL | IUCLC |
		       IXANY | IXON | IXOFF | INPCK | ISTRIP);
  options.c_iflag |= (BRKINT | IGNPAR);
  options.c_oflag &= ~OPOST;
  options.c_lflag &= ~(XCASE|ECHONL|NOFLSH);
  options.c_lflag &= ~(ICANON | ISIG | ECHO);//在用write发送数据时没有键入回车，信息就将发送不出去的情况，这主要是因为我们在输出输入时是按照 规范模式接受到回车或者换行才发送，而很多情况我们是不需要回车和换行的，这时，应当切换到行方式输入;不经处理直接发送。
  options.c_cflag |= CREAD;
  options.c_cc[VTIME] = 5;
  options.c_cc[VMIN] = 1;

  if (tcsetattr(fd,TCSANOW,&options) != 0)   
    { 
      perror("SetupSerial 3");   
      return (FALSE);  
    } 
  return (TRUE);  
}

/*********************************************************************/
int OpenDevR(char *Dev)
{
  int    fd = open(Dev, O_RDONLY | O_NOCTTY); 
  //| O_NOCTTY | O_NDELAY    
  if (-1 == fd)    
    {             
      perror("Can't Open Serial Port Read");
      return -1;        
    }    
  else    
    return fd;
}

int OpenDevW(char *Dev)
{
  int    fd = open(Dev, O_WRONLY); 
  //| O_NOCTTY | O_NDELAY    
  if (-1 == fd)    
    {             
      perror("Can't Open Serial Port Write");
      return -1;        
    }    
  else    
    return fd;
}

int OpenDev(char *Dev)
{
  int fd = open(Dev, O_RDWR | O_NOCTTY); 
  //| O_NOCTTY | O_NDELAY    
  if (-1 == fd)    
    {             
      perror("Can't Open Serial Port");
      return -1;        
    }    
  else    
    return fd;
}




int main(int argc, char *argv[])
{
  int rfd,wfd,fd;
  int nread;
  char buff[10240];
  char *dev  = (char *)"/dev/ttyUSB2";
  // rfd = OpenDevR(dev);
  // wfd = OpenDevW(dev);
  fd = OpenDev(dev);
  
  fcntl(fd, F_SETFL, FNDELAY);// 使read函数立即返回而不阻塞。FNDELAY选项使read函数在串口无字符时立即返回且为0。
  
  set_speed(fd,9600);
  
  if (set_Parity(fd,8,1,'N') == FALSE)  {
    printf("Set Parity Error\n");
    exit (0);
  }

  int n;
  
  // n=write(wfd,"HELP\r",5); 
  // if (n<0) 
  //   printf("write() of 5 bytes failed!\n"); 


  while (1) //循环读取数据
    {
      char str[512];
      fgets(str, 512, stdin);
      // printf("#############\n");
      // printf("%s\n\n",str);
      // printf("#############\n");

      if(str[0] == 'E' && str[1] == 'X' && str[2] == 'I' && str[3] == 'T') break;
      
      int L;
      for (L = 0; L < 512; ++L)
	{
	  if(str[L] == '\0')
	    {
	      str[L-1] = '\r';
	      // str[L+1] = '\0';
	      break;
	    }
	}
      // printf("@@ %d\n",L);
      // printf("%d\n",str[0]);
      // printf("===  %s\n",str);
      
      n=write(fd,str,L); 
      if (n<0) 
	printf("write() of 5 bytes failed!\n"); 

      sleep(1);
      
      while((nread = read(fd, buff, 10240))>0)
  	{ 
  	  printf("\nLen %d\n",nread); 
  	  buff[nread+1] = '\0';
  	  printf( "%s", buff);
  	}
      
      for (int i = 0; i < 10240; ++i)
	{
	  buff[i] = '\0';
	}
    }

  // n=write(fd,"DISPLAY SETTINGS\r",17); 
  // if (n<0) 
  //   printf("write() of 17 bytes failed!\n"); 
  
  // while (1) //循环读取数据
  //   {   
  //     while((nread = read(fd, buff, 512))>0)
  // 	{ 
  // 	  // printf("\nLen %d\n",nread); 
  // 	  buff[nread+1] = '\0';   
  // 	  printf( "%s", buff);   
  // 	}
  //   }

  
  close(fd);  
  // exit (0);
  
  return 0;
}

// 
// main.cc ends here
