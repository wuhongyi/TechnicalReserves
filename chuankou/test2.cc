// test2.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 1月  1 10:02:18 2017 (+0800)
// Last-Updated: 日 1月  1 10:02:52 2017 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 


http://www.cnblogs.com/b2tang/archive/2009/07/05/1517155.html

linux下如何对串口编程

Linux操作系统从一开始就对串行口提供了很好的支持，本文就Linux下的串行口通讯编程进行简单的介绍。

　　串口简介
串行口是计算机一种常用的接口，具有连接线少，通讯简单，得到广泛的使用。常用的串口是RS-232-C接口(又称EIA RS-232-C)它是在1970年由美国电子工业协会(EIA)联合贝尔系统、调制解调器厂家及计算机终端生产厂家共同制定的用于串行通讯的标准。它的全名是"数据终端设备(DTE)和数据通讯设备(DCE)之间串行二进制数据交换接口技术标准"该标准规定采用一个25个脚的DB25连接器，对连接器的每个引脚的信号内容加以规定，还对各种信号的电平加以规定。传输距离在码元畸变小于4%的情况下，传输电缆长度应为50英尺。

　　Linux操作系统从一开始就对串行口提供了很好的支持，本文就Linux下的串行口通讯编程进行简单的介绍，如果要非常深入了解，建议看看本文所参考的《Serial Programming Guide for POSIX Operating Systems》

　　串口操作

　　串口操作需要的头文件
复制代码
1 #include     <stdio.h>      /*标准输入输出定义*/
2 #include     <stdlib.h>     /*标准函数库定义*/
3 #include     <unistd.h>     /*Unix 标准函数定义*/
4 #include     <sys/types.h>  
5 #include     <sys/stat.h>   
6 #include     <fcntl.h>      /*文件控制定义*/
7 #include     <termios.h>    /*PPSIX 终端控制定义*/
8 #include     <errno.h>      /*错误号定义*/
复制代码

打开串口

在 Linux 下串口文件是位于 /dev 下的。串口一 为 /dev/ttyS0，串口二 为 /dev/ttyS1。打开串口是通过使用标准的文件打开函数操作：
复制代码
1 int fd;
2 /*以读写方式打开串口*/
3 fd = open( "/dev/ttyS0", O_RDWR);
4 if (-1 == fd){ 
5 /* 不能打开串口一*/ 
6 perror(" 提示错误！");
7 }
复制代码

设置串口

最基本的设置串口包括波特率设置，效验位和停止位设置。串口的设置主要是设置 struct termios 结构体的各成员值。
复制代码
1 struct termio
2 {    unsigned short  c_iflag;    /* 输入模式标志 */    
3     unsigned short  c_oflag;        /* 输出模式标志 */    
4     unsigned short  c_cflag;        /* 控制模式标志*/    
5     unsigned short  c_lflag;        /* local mode flags */    
6     unsigned char  c_line;            /* line discipline */    
7     unsigned char  c_cc[NCC];    /* control characters */
8 };
复制代码

设置这个结构体很复杂，我这里就只说说常见的一些设置：

波特率设置 下面是修改波特率的代码：

1 struct  termios Opt;
2 tcgetattr(fd, &Opt);
3 cfsetispeed(&Opt,B19200);     /*设置为19200Bps*/
4 cfsetospeed(&Opt,B19200);
5 tcsetattr(fd,TCANOW,&Opt);

设置波特率的例子函数：

复制代码
 1 /**
 2 *@brief  设置串口通信速率
 3 *@param  fd     类型 int  打开串口的文件句柄
 4 *@param  speed  类型 int  串口速度
 5 *@return  void
 6 */
 7 int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,
 8         B38400, B19200, B9600, B4800, B2400, B1200, B300, };
 9 int name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400,  
10             19200,  9600, 4800, 2400, 1200,  300, };
11 void set_speed(int fd, int speed){
12     int   i; 
13     int   status; 
14     struct termios   Opt;
15     tcgetattr(fd, &Opt); 
16     for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++) { 
17         if  (speed == name_arr[i]) {     
18             tcflush(fd, TCIOFLUSH);     
19             cfsetispeed(&Opt, speed_arr[i]);  
20             cfsetospeed(&Opt, speed_arr[i]);   
21             status = tcsetattr(fd1, TCSANOW, &Opt);  
22             if  (status != 0) {        
23                 perror("tcsetattr fd1");  
24                 return;     
25             }    
26             tcflush(fd,TCIOFLUSH);   
27         }  
28     }
29 }
复制代码

设置效验的函数：

复制代码
 1 /**
 2 *@brief   设置串口数据位，停止位和效验位
 3 *@param  fd     类型  int  打开的串口文件句柄
 4 *@param  databits 类型  int 数据位   取值 为 7 或者8
 5 *@param  stopbits 类型  int 停止位   取值为 1 或者2
 6 *@param  parity  类型  int  效验类型 取值为N,E,O,,S
 7 */
 8 int set_Parity(int fd,int databits,int stopbits,int parity)
 9 { 
10     struct termios options; 
11     if  ( tcgetattr( fd,&options)  !=  0) { 
12         perror("SetupSerial 1");     
13         return(FALSE);  
14     }
15     options.c_cflag &= ~CSIZE; 
16     switch (databits) /*设置数据位数*/
17     {   
18     case 7:        
19         options.c_cflag |= CS7; 
20         break;
21     case 8:     
22         options.c_cflag |= CS8;
23         break;   
24     default:    
25         fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
26     }
27 switch (parity) 
28 {   
29     case 'n':
30     case 'N':    
31         options.c_cflag &= ~PARENB;   /* Clear parity enable */
32         options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
33         break;  
34     case 'o':   
35     case 'O':     
36         options.c_cflag |= (PARODD | PARENB); /* 设置为奇效验*/  
37         options.c_iflag |= INPCK;             /* Disnable parity checking */ 
38         break;  
39     case 'e':  
40     case 'E':   
41         options.c_cflag |= PARENB;     /* Enable parity */    
42         options.c_cflag &= ~PARODD;   /* 转换为偶效验*/     
43         options.c_iflag |= INPCK;       /* Disnable parity checking */
44         break;
45     case 'S': 
46     case 's':  /*as no parity*/   
47         options.c_cflag &= ~PARENB;
48         options.c_cflag &= ~CSTOPB;break;  
49     default:   
50         fprintf(stderr,"Unsupported parity\n");    
51         return (FALSE);  
52     }  
53 /* 设置停止位*/  
54 switch (stopbits)
55 {   
56     case 1:    
57         options.c_cflag &= ~CSTOPB;  
58         break;  
59     case 2:    
60         options.c_cflag |= CSTOPB;  
61        break;
62     default:    
63          fprintf(stderr,"Unsupported stop bits\n");  
64          return (FALSE); 
65 } 
66 /* Set input parity option */ 
67 if (parity != 'n')   
68     options.c_iflag |= INPCK; 
69 tcflush(fd,TCIFLUSH);
70 options.c_cc[VTIME] = 150; /* 设置超时15 seconds*/   
71 options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
72 if (tcsetattr(fd,TCSANOW,&options) != 0)   
73 { 
74     perror("SetupSerial 3");   
75     return (FALSE);  
76 } 
77 return (TRUE);  
78 }
复制代码

需要注意的是: 如果不是开发终端之类的，只是串口传输数据，而不需要串口来处理，那么使用原始模式(Raw Mode)方式来通讯，设置方式如下：
1 options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
2 options.c_oflag  &= ~OPOST;   /*Output*/

读写串口

设置好串口之后，读写串口就很容易了，把串口当作文件读写就是。

·发送数据
1 char  buffer[1024];
2 int    Length;
3 int    nByte;nByte = write(fd, buffer ,Length)

·读取串口数据
使用文件操作read函数读取，如果设置为原始模式(Raw Mode)传输数据，那么read函数返回的字符数是实际串口收到的字符数。可以使用操作文件的函数来实现异步读取，如fcntl，或者select等来操作。
1 char  buff[1024];
2 int    Len;
3 int  readByte = read(fd,buff,Len);

关闭串口

关闭串口就是关闭文件。
1 close(fd);

例子

下面是一个简单的读取串口数据的例子，使用了上面定义的一些函数和头文件
复制代码
 1 /**********************************************************************
 2 代码说明：使用串口二测试的，发送的数据是字符，
 3 但是没有发送字符串结束符号，所以接收到后，后面加上了结束符号。
 4 我测试使用的是单片机发送数据到第二个串口，测试通过。
 5 **********************************************************************/
 6 #define FALSE  -1
 7 #define TRUE   0
 8 /*********************************************************************/
 9 int OpenDev(char *Dev)
10 {
11     int    fd = open( Dev, O_RDWR ); 
12         //| O_NOCTTY | O_NDELAY    
13     if (-1 == fd)    
14     {             
15         perror("Can't Open Serial Port");
16         return -1;        
17     }    
18     else    
19         return fd;
20 }
21 int main(int argc, char **argv){
22     int fd;
23     int nread;
24     char buff[512];
25     char *dev  = "/dev/ttyS1"; //串口二
26     fd = OpenDev(dev);
27     set_speed(fd,19200);
28     if (set_Parity(fd,8,1,'N') == FALSE)  {
29         printf("Set Parity Error\n");
30         exit (0);
31     }
32 while (1) //循环读取数据
33 {   
34     while((nread = read(fd, buff, 512))>0)
35     { 
36         printf("\nLen %d\n",nread); 
37         buff[nread+1] = '\0';   
38         printf( "\n%s", buff);   
39     }
40 }
41     //close(fd);  
42     // exit (0);
43 }
复制代码

// 
// test2.cc ends here
