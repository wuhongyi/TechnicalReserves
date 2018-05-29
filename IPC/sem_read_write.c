

#include <stdio.h>
#include <stdlib.h>
#include "pv.h"
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
typedef struct Result
{
	int sum;
	int semid;
}Result;

void write_result(Result*r, int val)
{
	r->sum = val;
	printf("%d write: %d\n", getpid(), val);
	V(r->semid, 0, 1);
	P(r->semid, 1, 1);
}

int read_result(Result*r)
{
	P(r->semid, 0, 1);
	int ret = r->sum;
	printf("%d read: %d\n", getpid(), ret);
	V(r->semid, 1, 1);
	return ret;
}

int main(void)
{
	int shmid = shmget(IPC_PRIVATE, sizeof(Result),
				IPC_CREAT|IPC_EXCL|0777);
	if(shmid < 0){
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}
	Result* addr =(Result*)shmat(shmid, 0, 0);
	if(addr == (Result*)-1){
		fprintf(stderr, "%s\n",strerror(errno));
		exit(1);
	}
    addr->semid = I(2, 0);
	pid_t pid;
	pid = fork();
	if(pid < 0){
		fprintf(stderr, "%s\n",strerror(errno));
		exit(1);
	}else if(pid > 0){   //write
		int i = 1;
		int sum = 0;
		for(i; i <= 100; i++)
		{
			sum += i;
			usleep((long)(drand48()*1000000));
			write_result(addr, sum);
		}
		wait(0);
		D(addr->semid);
		shmdt(addr);
		shmctl(shmid, IPC_RMID, NULL);
	}else{         //read
	    int i = 1;
		for(i; i <= 100; i++){
			usleep((long)drand48()*1000000);
			read_result(addr);
		}
		//D(addr->semid);
		shmdt(addr);
	}
	
	return 0;
}



