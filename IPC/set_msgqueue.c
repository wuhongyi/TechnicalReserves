

// g++ set_msgqueue.c -o 123
// ./123 /var

// 查看消息队列
// ipcs -q

//删除消息队列
// ipcrm -q  [msqid]


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/msg.h>

typedef struct Msg
{
  int mtype;//优先级
    int start;
    int end;
}Msg;


int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"usage:%s\n",argv[1]);
        exit(1);
    }
    key_t key = ftok(argv[1],1);//第一个参数为路径，路径相同key才能相同，所以放数据跟取数据路径得相同。第二个参数为int数，随便指定。
    long int msq_id;
    if((msq_id = msgget(key,IPC_CREAT|IPC_EXCL|0777)) < 0)
    {
        fprintf(stderr,"msgget : %s\n",strerror(errno));
        exit(1);
    }
    Msg m1 = {1,10,100};
    Msg m2 = {2,20,200};
    Msg m3 = {3,30,300};
    Msg m4 = {5,50,500};

    if(msgsnd(msq_id,&m1,sizeof(m1),IPC_NOWAIT)<0
            || msgsnd(msq_id,&m2,sizeof(m1),IPC_NOWAIT)<0
            || msgsnd(msq_id,&m3,sizeof(m1),IPC_NOWAIT)<0
            || msgsnd(msq_id,&m4,sizeof(m1),IPC_NOWAIT)<0) //发送消息
    {
        fprintf(stderr,"snd:%s\n",strerror(errno));
        exit(1);
    }
    struct msqid_ds msq_attr;
    if(msgctl(msq_id,IPC_STAT,&msq_attr) < 0)//查看消息队列属性
    {
        fprintf(stderr,"msgctl:%s\n",strerror(errno));
        exit(1);
    }
    else
    {
        printf("msg num: %ld\n",msq_attr.msg_qnum);
        printf("msg bytes: %ld\n",msq_attr.msg_qbytes);
    }

    return 0;
}
