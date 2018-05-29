/* c.c --- 
 * 
 * Description: 
 * Author: Hongyi Wu(吴鸿毅)
 * Email: wuhongyi@qq.com 
 * Created: 五 10月 23 16:16:52 2015 (+0800)
 * Last-Updated: 五 10月 23 16:59:45 2015 (+0800)
 *           By: Hongyi Wu(吴鸿毅)
 *     Update #: 24
 * URL: http://wuhongyi.cn */

/* http://blog.csdn.net/tjssehaige/article/details/8546849 */
/* 主要实现：发送20个文本消息，然后再发送一个终止消息  */
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netdb.h>  
  
int port=6789;  
int main(int argc, char** argv) {  
  int socket_descriptor; //套接口描述字  
  int iter=0;  
  char buf[500];  
  struct sockaddr_in address;//处理网络通信的地址  
  
  bzero(&address,sizeof(address));  
  address.sin_family=AF_INET;  
  address.sin_addr.s_addr=inet_addr("127.0.0.1");//这里不一样  
  address.sin_port=htons(port);  
  
  //创建一个 UDP socket  
  
  socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);//IPV4  SOCK_DGRAM 数据报套接字（UDP协议）  
  
  for(iter=0;iter<=400000;iter++)  
    {  
      /* sprintf(buf,"data packet with ID %d\n",iter);  */ 

      sprintf(buf,"AAAAAAAAAAAAAAAAAAAAABBBBBBBBCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDEEEEEEEEEEEEFFFFFFFFFFFGGGGGGGGGGGGGGGXXXXXXXXXXXXXXXXXXXX data packet with ID %d\n",iter);
      usleep(1);         
      /* sleep(1); */

      /*int PASCAL FAR sendto( SOCKET s, const char FAR* buf, int len, int flags,const struct sockaddr FAR* to, int tolen);　　 
       * s：一个标识套接口的描述字。　 
       * buf：包含待发送数据的缓冲区。　　 
       * len：buf缓冲区中数据的长度。　 
       * flags：调用方式标志位。　　 
       * to：（可选）指针，指向目的套接口的地址。　 
       * tolen：to所指地址的长度。   
       　　      */  
      sendto(socket_descriptor,buf,sizeof(buf),0,(struct sockaddr *)&address,sizeof(address));  
    }  
  
  sprintf(buf,"stop\n");  
  sendto(socket_descriptor,buf,sizeof(buf),0,(struct sockaddr *)&address,sizeof(address));//发送stop 命令  
  close(socket_descriptor);  
  printf("Messages Sent,terminating\n");  
  
  exit(0);  
  
  return (EXIT_SUCCESS);  
}  

/* c.c ends here */
