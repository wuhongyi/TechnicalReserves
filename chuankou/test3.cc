// test3.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 1月  1 10:03:34 2017 (+0800)
// Last-Updated: 日 1月  1 10:03:49 2017 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

http://www.cnblogs.com/b2tang/archive/2009/07/05/1517158.html

 详解linux下的串口通讯开发
	

串行口是计算机一种常用的接口，具有连接线少，通讯简单，得到广泛的使用。常用的串口是RS-232-C接口(又称EIA RS-232-C)它是在1970年由美国电子工业协会(EIA)联合贝尔系统、调制解调器厂家及计算机终端生产厂家共同制定的用于串行通讯的标准。串口通讯指的是计算机依次以位（bit）为单位来传送数据，串行通讯使用的范围很广，在嵌入式系统开发过程中串口通讯也经常用到通讯方式之一。

Linux对所有设备的访问是通过设备文件来进行的，串口也是这样，为了访问串口，只需打开其设备文件即可操作串口设备。在linux系统下面，每一个串口设备都有设备文件与其关联，设备文件位于系统的/dev目录下面。如linux下的/ttyS0，/ttyS1分别表示的是串口1和串口2。下面来详细介绍linux下是如何使用串口的：

1.      串口操作需要用到的头文件
复制代码
 1 #include     <stdio.h>      /*标准输入输出定义*/
 2 
 3 #include     <stdlib.h>     /*标准函数库定义*/
 4 
 5 #include     <unistd.h>     /*Unix 标准函数定义*/
 6 
 7 #include     <sys/types.h> 
 8 
 9 #include     <sys/stat.h>   
10 
11 #include     <fcntl.h>      /*文件控制定义*/
12 
13 #include     <termios.h>    /*POSIX 终端控制定义*/
14 
15 #include     <errno.h>      /*错误号定义*/
16 
17 #include   <string.h>       /*字符串功能函数*/
18 
复制代码


2.      串口通讯波特率设置

波特率的设置定义在<asm/termbits.h>，其包含在头文件<termios.h>里。

常用的波特率常数如下：

B0-------à0                     B1800-------à1800

B50-----à50                    B2400------à2400

B75-----à75                    B4800------à4800

B110----à110                 B9600------à9600

B134----à134.5              B19200-----à19200

B200----à200                 B38400------à38400

B300----à300                 B57600------à57600

B600----à600                 B76800------à76800

B1200---à1200              B115200-----à115200


假定程序中想要设置通讯的波特率，使用cfsetispeed( )和cfsetospeed( )函数来操作，获取波特率信息是通过cfgetispeed（）和cfgetospeed（）函数来完成的。比如可以这样来指定串口通讯的波特率：

复制代码
 1 #include <stdio.h>    //头文件定义
 2 
 3 ..
 4 
 5 struct termios opt；           /*定义指向termios 结构类型的指针opt*/
 6 
 7  /***************以下设置通讯波特率****************/
 8 
 9 cfsetispeed(&opt，B9600 )； /*指定输入波特率，9600bps*/
10 
11 cfsetospeed(&opt，B9600)；/*指定输出波特率，9600bps*/
12 
13 /************************************************/
14 
15 
16 
17 
复制代码


一般来说，输入、输出的波特率应该是一致的。

3.      串口属性配置

在程序中，很容易配置串口的属性，这些属性定义在结构体struct termios中。为在程序中使用该结构体，需要包含文件<termbits.h>，该头文件定义了结构体struct termios。该结构体定义如下：

复制代码
 1 #define NCCS 19
 2 
 3 struct termios {
 4 
 5              tcflag_t c_iflag;               /* 输入参数 */
 6 
 7              tcflag_t c_oflag;               /* 输出参数 */
 8 
 9              tcflag_t c_cflag;               /* 控制参数*/
10 
11              tcflag_t c_ispeed;              /* 输入波特率 */
12 
13 tcflag_t c_ospeed;              /* 输出波特率 */
14 
15              cc_t c_line;                   /* 线控制 */
16 
17              cc_t c_cc[NCCS];              /* 控制字符*/
18 
19 };
20 
复制代码


其中成员c_line在POSIX(Portable Operating System Interface for UNIX)系统中不使用。对于支持POSIX终端接口的系统中，对于端口属性的设置和获取要用到两个重要的函数是：

（1）.int tcsetattr（int fd，int opt_DE，*ptr）
该函数用来设置终端控制属性，其参数说明如下：
l        fd：待操作的文件描述符
l        opt_DE：选项值，有三个选项以供选择：
TCSANOW： 不等数据传输完毕就立即改变属性
TCSADRAIN：等待所有数据传输结束才改变属性
TCSAFLUSH：清空输入输出缓冲区才改变属性
l        *ptr：指向termios结构的指针

函数返回值：成功返回0，失败返回－1。
（2）.int tcgetattr（int fd，*ptr）

该函数用来获取终端控制属性，它把串口的默认设置赋给了termios数据数据结构，其参数说明如下：
l    fd：待操作的文件描述符
l        *ptr：指向termios结构的指针

函数返回值：成功返回0，失败返回－1。

4.      打开串口

在前面已经提到linux下的串口访问是以设备文件形式进行的，所以打开串口也即是打开文件的操作。函数原型可以如下所示：

int open（“DE_name”，int open_Status）
参数说明：
（1）.DE_name：要打开的设备文件名
比如要打开串口1，即为/dev/ttyS0。
（2）.open_Status：文件打开方式，可采用下面的文件打开模式：
l          O_RDONLY：以只读方式打开文件
l          O_WRONLY：以只写方式打开文件
l          O_RDWR：以读写方式打开文件
l          O_APPEND：写入数据时添加到文件末尾
l          O_CREATE：如果文件不存在则产生该文件，使用该标志需要设置访问权限位mode_t
l          O_EXCL：指定该标志，并且指定了O_CREATE标志，如果打开的文件存在则会产生一个错误
l          O_TRUNC：如果文件存在并且成功以写或者只写方式打开，则清除文件所有内容，使得文件长度变为0
l          O_NOCTTY：如果打开的是一个终端设备，这个程序不会成为对应这个端口的控制终端，如果没有该标志，任何一个输入，例如键盘中止信号等，都将影响进程。
l          O_NONBLOCK：该标志与早期使用的O_NDELAY标志作用差不多。程序不关心DCD信号线的状态，如果指定该标志，进程将一直在休眠状态，直到DCD信号线为0。

函数返回值：
成功返回文件描述符，如果失败返回-1
例如假定以可读写方式打开/dev/ttyS0设备，就可以这样操作：

 
复制代码
 1 #include<stdio.h>    //头文件包含
 2 
 3 
 4 
 5 int fd; /* 文件描述符 */ 
 6 
 7 fd = open("/dev/ttyS0", O_RDWR | 0_NOCTTY)； /*以读写方式打开设备*/
 8 
 9 if(fd == -1)
10 
11 perror("Can not open Serial_Port 1"n！")；/*打开失败时的错误提示*/
12 
13 .. 
14 
15 
复制代码

 
5.      串口读操作（接收端）

用open函数打开设备文件，函数返回一个文件描述符(file descriptors,fd)，通过文件描述符来访问文件。读串口操作是通过read函数来完成的。函数原型如下：
int read(int fd, *buffer,length)；
参数说明：
（1）.int fd：文件描述符
（2）.*buffer：数据缓冲区
（3）.length：要读取的字节数
函数返回值：
读操作成功读取返回读取的字节数，失败则返回-1。

6.      串口写操作（发送端）
写串口操作是通过write函数来完成的。函数原型如下：
write(int fd, *buffer,length);
参数说明：
（1）.fd：文件描述符
（2）.*buffer：存储写入数据的数据缓冲区
（3）.length：写入缓冲去的数据字节数
函数返回值：
成功返回写入数据的字节数,该值通常等于length，如果写入失败返回-1。
例如：向终端设备发送初始化命令

复制代码
 1 #include<stdio.h>    //头文件包含
 2 
 3 
 4 int n 
 5 
 6 sbuf[]={Hello，this is a Serial_Port test！"n }；//待发送数据
 7 
 8 int len_send="sizeof"（sbuf）；//发送缓冲区字节数定义
 9 
10 n = write(fd,sbuf,len_send); //写缓冲区
11 
12 if(n == -1) 
13 
14 { 
15 
16 printf("Wirte sbuf error."n"); 
17 
18 } 
19 
复制代码

7.      关闭串口
对设备文件的操作与对普通文件的操作一样，打开操作之后还需要关闭，关闭串口用函数close( )来操作，函数原型为：
int close(int fd);
参数说明：
fd：文件描述符
函数返回值：
成功返回0，失败返回-1。

// 
// test3.cc ends here
