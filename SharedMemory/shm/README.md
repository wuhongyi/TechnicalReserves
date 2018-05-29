<!-- README.md --- 
;; 
;; Description: 
;; Author: Hongyi Wu(吴鸿毅)
;; Email: wuhongyi@qq.com 
;; Created: 二 6月 21 15:13:35 2016 (+0800)
;; Last-Updated: 二 6月 21 15:19:39 2016 (+0800)
;;           By: Hongyi Wu(吴鸿毅)
;;     Update #: 2
;; URL: http://wuhongyi.cn -->

Posix共享内存区涉及两个步骤：

- 指定一个名字参数调用shm_open,以创建一个新的共享内存区对象或打开一个以存在的共享内存区对象。
- 调用mmap把这个共享内存区映射到调用进程的地址空间。传递给shm_open的名字参数随后由希望共享该内存区的任何其他进程使用。



```
shm_open()函数
功能：    打开或创建一个共享内存区
头文件：    #include <sys/mman.h>
函数原形：    int shm_open(const char *name,int oflag,mode_t mode);
返回值：    成功返回0，出错返回-1
参数：    
    name    共享内存区的名字
    oflag    标志位
    mode    权限位

参数解释：oflag参数必须含有O_RDONLY和O_RDWR标志，还可以指定如下标志：O_CREAT,O_EXCL或O_TRUNC.mode参数指定权限位，
它指定O_CREAT标志的前提下使用。shm_open的返回值是一个整数描述字，它随后用作mmap的第五个参数。

shm_unlink()函数
功能：    删除一个共享内存区
头文件：    #include <sys/mman.h>
函数原形：    int shm_unlink(const char *name);
参数：     name    共享内存区的名字
返回值：    成功返回0，出错返回-1

shm_unlink函数删除一个共享内存区对象的名字，删除一个名字仅仅防止后续的open,mq_open或sem_open调用取得成功。
```

```cpp
/*shm_open.c创建共享内存区*/
// gcc -lrt -o shm_open shm_open.c
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
    int shm_id;

    if(argc!=2)
    {
        printf("usage:shm_open <pathname>\n");
        exit(1);
    }
    shm_id=shm_open(argv[1],O_RDWR|O_CREAT,0644);
    printf("shmid:%d\n",shm_id);
    shm_unlink(argv[1]);
}
```

```
ftruncate()函数 3 功能：    调整文件或共享内存区大小
头文件：    #include <unistd.h>
函数原形：    int ftruncate(int fd,off_t length);
参数：    
    fd          描述符
    length       大小
返回值：    成功返回0，出错返回-1

当打开一个已存在的共享内存区对象时，我们可调用fstat来获取有关该对象的信息

fstat()函数
功能：    获得文件或共享内存区的信息
头文件：    #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
函数原形：    int stat(const char *file_name,struct stat *buf);
参数：    
file_name          文件名
buf               stat结构
返回值：    成功返回0，出错返回-1

对于普通文件stat结构可以获得12个以上的成员信息，然而当fd指代一个共享内存区对象时，只有四个成员含有信息。
struct stat{
    mode_t st_mode;
    uid_t st_uid;
    gid_t st_gid;
    off_t st_size;
};
```

```cpp
/*shm_show.c显示共享区信息*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc,char **argv)
{
    int shm_id;
        struct stat buf;

        if(argc!=2)
        {
            printf("usage:shm_open <pathname>\n");
            exit(1);
        }
        shm_id=shm_open(argv[1],O_RDWR|O_CREAT,0644);/*创建共享内存*/
        printf("size :%d\n",buf.st_size); /*修改前共享内存区大小*/
        ftruncate(shm_id,100);/*修改共享内存的大小*/
        fstat(shm_id,&buf); /*把共享内存的信息记录到buf中*/
        printf("uid_t:%d\n",buf.st_uid); /*共享内存区所有者ID*/
        printf("git_t:%d\n",buf.st_gid); /*共享内存区所有者组ID*/
        printf("size :%d\n",buf.st_size); /*修改后共享内存区大小*/
}
```

```
root@linux:/mnt/hgfs/C_libary# gcc -lrt -o shm_show shm_show.c
shm_show.c: In function ‘main’:
shm_show.c:20: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘__off_t’
shm_show.c:25: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘__off_t’

/* 内容来自互联网
        有人提出来在sys/types.h里面加上 typedef long __off_t; typedef long __time_t; 
        
        小鱼我看了一下源文件,认为上面的说法还是有问题的，露了off_t和time_t
        #ifndef __off_t_defined 
        # ifndef __USE_FILE_OFFSET64 
        typedef __off_t off_t; 
        # else 
        typedef __off64_t off_t; 
        # endif 
        # define __off_t_defined 
        #endif  
        
        如果定义了__USE_FILE_OFFSET64 就把off_t定义为__off64_t ，否则定义为32位（传说中的大文件支持处理） 
        ------------------------------
        其实没必要casting。直接用%ld换掉%d就行了，因为是long int所以%d会抛警告的 
*/
root@linux:/mnt/hgfs/C_libary# gcc -lrt -o shm_show shm_show.c
root@linux:/mnt/hgfs/C_libary# 
root@linux:/mnt/hgfs/C_libary# ./shm_show test
size :4983648
uid_t:0
git_t:0
size :100
root@linux:/mnt/hgfs/C_libary#
```

共享内存区的写入和读出

　　前面我们介绍了mmap函数，下面我们就可以通过这些函数，把进程映射到共享内存区。然后我们就可以通过共享内存区进行进程间通信了。

```cpp
/*shm_write.c写入/读出共享内存区*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc,char **argv)
{
    int shm_id;
    struct stat buf;
    char *ptr;

    if(argc!=2)
    {
        printf("usage:shm_open <pathname>\n");
        exit(1);
    }
    shm_id=shm_open(argv[1],O_RDWR|O_CREAT,0644);/*创建共享内存区*/
    ftruncate(shm_id,100);/*修改共享区大小*/
    fstat(shm_id,&buf);
    ptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,shm_id,0);/*连接共享内存区*/
    strcpy(ptr,"hello linux");/*写入共享内存区*/
    printf("%s\n",ptr);/*读出共享内存区*/
    shm_unlink(argv[1]);/*删除共享内存区*/
}
```





<!-- README.md ends here -->
