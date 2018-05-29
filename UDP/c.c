/* c.c --- 
 * 
 * Description: 
 * Author: Hongyi Wu(吴鸿毅)
 * Email: wuhongyi@qq.com 
 * Created: 五 10月 23 15:57:58 2015 (+0800)
 * Last-Updated: 五 10月 23 16:14:04 2015 (+0800)
 *           By: Hongyi Wu(吴鸿毅)
 *     Update #: 3
 * URL: http://wuhongyi.cn */

#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>/*包含相关的头文件。*/

#define REMOTEPORT 4567  /*定义表示端口号的常量。*/
#define REMOTEIP "192.168.1.104"  /*定义表示表 IP 的常量。*/

int main(int argc,char *argv[])
{
  int s,len;/*定义相关的变量。*/
  struct sockaddr_in addr;
  int addr_len;
  char msg[256];/*定义一个数组发送与接收数据。*/
  int i=0;

  if (( s= socket(AF_INET, SOCK_DGRAM, 0) )<0)/*建立一个 socket。*/
    {
      perror("error");/*输出错误。*/

      exit(1);
    }
  else
    {
      printf("socket created .\n");/*输出提示信息。*/
      printf("socked id: %d \n",s);
      printf("remote ip: %s \n",REMOTEIP);
      printf("remote port: %d \n",REMOTEPORT);
    }

  len=sizeof(struct sockaddr_in);/*长度。*/
  bzero(&addr,sizeof(addr));/*空间地址结构体所在的内存空间。*/
  addr.sin_family=AF_INET;/*填充地址与端口的信息。*/
  addr.sin_port=htons(REMOTEPORT);/*端口。*/
  addr.sin_addr.s_addr=inet_addr(REMOTEIP);

  while (1)/*循环。*/
    {
      bzero(msg,sizeof(msg));/*清空 msg 所在的内存。*/
      len = read(STDIN_FILENO,msg,sizeof(msg));/*接收信息。*/
      sendto(s,msg,len,0,&addr,addr_len);/*发送信息。*/
      printf("\nInput message: %s \n",msg);/*输出结果。*/
      len= recvfrom (s,msg,sizeof(msg),0,&addr,&addr_len);/*这是接收到的信息。*/
      printf("%d :",i);/*输出计数。*/
      i++;/*计数自加。*/
      printf("Received message: %s \n",msg);/*这是服务器返回的信息。*/
    }

  return 0;
}




/* c.c ends here */
