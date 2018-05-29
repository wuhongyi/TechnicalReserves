/* s.c --- 
 * 
 * Description: 
 * Author: Hongyi Wu(吴鸿毅)
 * Email: wuhongyi@qq.com 
 * Created: 五 10月 23 16:03:03 2015 (+0800)
 * Last-Updated: 五 10月 23 16:09:16 2015 (+0800)
 *           By: Hongyi Wu(吴鸿毅)
 *     Update #: 2
 * URL: http://wuhongyi.cn */

#include<stdio.h>
#include <stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>/*包含相关的头文件。*/

#define LOCALPORT 4567


int main(int argc,char *argv[])
{
  int mysock,len;/*定义相关的变量。*/
  struct sockaddr_in addr;
  int i=0;
  char msg[256];/*定义一个数组,保存发送与接收的信息。*/
  int addr_len;


  if (( mysock= socket(AF_INET, SOCK_DGRAM, 0) )<0)/*建立一个连接。*/
    {
      perror("error");/*输出错误。*/
      exit(1);
    }
  else/*socket 建立成功则提示信息。*/
    {
      printf("socket created .\n");
      printf("socked id: %d \n",mysock);
    }

  addr_len=sizeof(struct sockaddr_in);/*长度。*/
  bzero(&addr,sizeof(addr));/*清空地址所在的内存。*/
  addr.sin_family=AF_INET;/*填充地址结构体。*/
  addr.sin_port=htons(LOCALPORT);
  addr.sin_addr.s_addr=htonl(INADDR_ANY);

  if(bind(mysock,&addr,sizeof(addr))<0) /*在 socket 上面绑定端口号与 IP。*/
    {
      perror("connect");/*输出错误信息。*/
      exit(1);
    }
  else
    {
      printf("bind ok.\n");/*绑定成功则输出信息。*/
      printf("local port :%d \n",LOCALPORT);
    }

  while (1)/*进入一个循环。*/
    {
      bzero(msg,sizeof(msg));/*清空 msg 所在的内存。*/
      len= recvfrom (mysock,msg,sizeof(msg),0,&addr,&addr_len);/*接收到信息。*/
      printf("%d :",i);/*输出计数。*/
      i++;/*计数自加。*/
      printf("message from : %s \n",inet_ntoa(addr.sin_addr));/*输出 IP 地址。*/
      printf(" message length : %d \n",len);/*输出长度信息。*/
      printf(" message : %s \n\n",msg);/*输出信息。*/

      sendto(mysock,msg,len,0,&addr,addr_len);
      /*字符串返回给客户端*/
    }

  return 0;
}




/* s.c ends here */
