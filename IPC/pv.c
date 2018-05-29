


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/sem.h>
#include <assert.h>

union semun
{
	int val;
	struct semid_ds  *buf;
	unsigned short   *array;	
};

int I(int semnum, int var)//semnum是信号量个数。var控制+1，-1，+2，-2等
{
	int semid;
	semid = semget(IPC_PRIVATE, semnum, IPC_CREAT|IPC_EXCL|0777);//初始化
	if(semid < 0){
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}
    union semun se;
    unsigned short *array = 
		(unsigned short*)calloc(semnum, sizeof(unsigned short));
    assert(array != NULL);
    int i = 0;
	for(i; i < semnum; i++)
  		array[i] = var;

	se.array = array;
    if(semctl(semid, 0, SETALL, se) < 0){
		fprintf(stderr, "%s\n",strerror(errno));
		exit(1);
	}
    free(array);
	array =  NULL;
    return semid;
}
void P(int semid, int semnum, int var)
{
	assert(var >= 0);
	struct sembuf buf[1] = {semnum, -var, SEM_UNDO};
	if(semop(semid, buf, 1) < 0){
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}

}
void V(int semid, int semnum, int var)
{
	assert(var >= 0);
	struct sembuf buf[1] = {semnum, var, SEM_UNDO};
	if(semop(semid, buf, 1) < 0){
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}
}
void D(int semid)
{
  if(semctl(semid, 0, IPC_RMID)<0){//删除
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1);
	}
}





