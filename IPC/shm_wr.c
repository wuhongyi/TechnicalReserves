// 


#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


int main(void)
{
    int shm_id;
    if((shm_id = shmget(IPC_PRIVATE,100,IPC_CREAT|IPC_EXCL|0777)) < 0)
    {
        fprintf(stderr,"shmget:%s\n",strerror(errno));
        exit(1);
    }

    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        fprintf(stderr,"fork:%s\n",strerror(errno));
        exit(1);
    }
    else if(pid > 0)//父进程
    {
        int *addr = (int*)shmat(shm_id,0,0);
        if(addr == (int*)-1)//出错
        {
            fprintf(stderr,"shmat:%s\n",strerror(errno));
            exit(1);
        }
        *addr = 100;
        *(addr+1) = 200;
        wait(0);
        shmdt(addr);//
        shmctl(shm_id,IPC_RMID,NULL);//删除共享内存段
    }
    else
    {
        sleep(1);
        int *p = (int*)shmat(shm_id,0,0);
        if(p == (int*)-1)
        {
            fprintf(stderr,"shmat:%s\n",strerror(errno));
            exit(1);
        }
        int num1 = *p;
        int num2 = *(p+1);
        printf("num1: %d,num2: %d\n",num1,num2);
        shmdt(p);
    }
    return 0;

}
