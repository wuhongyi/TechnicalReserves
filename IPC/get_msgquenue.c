// g++ get_msgquenue.c -o 456
// ./456 /var 0




#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <errno.h>

typedef struct Msg
{
    int mtype;
    int start;
    int end;
}Msg;


int main(int argc,char *argv[])
{

    if(argc < 3)
    {
        fprintf(stderr,"usage:%s\n",argv[0]);
        exit(1);
    }
    key_t key;
    key = ftok(argv[1],1);
    int msq_id;
    if((msq_id = msgget(key,0777)) < 0)
    {
        fprintf(stderr,"msgget:%s\n",strerror(errno));
        exit(1);
    }

    int type = atoi(argv[2]);
    Msg m;
    if(msgrcv(msq_id,(void*)&m,sizeof(m),type,IPC_NOWAIT) < 0)
    {
        fprintf(stderr,"msgrcv:%s\n",strerror(errno));
        exit(1);
    }
    else
    {
        printf("type: %d,start: %d,end: %d\n",m.mtype,m.start,m.end);
    }

    return 0;
}
