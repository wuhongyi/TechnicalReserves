// test1.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 1月  1 09:59:14 2017 (+0800)
// Last-Updated: 日 1月  1 09:59:59 2017 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 1
// URL: http://wuhongyi.cn 

http://blog.csdn.net/sphone89/article/details/6756882

 串口通信编程（linux） 

rs232是三芯通信，即DB9的第2引脚RXD（接收）、第3引脚TXD（发送数据）、第5引脚DG（信号地）。

rs232是三芯通信，485是两芯通讯的，RS-232串口线 通常 是 DB9--DB9 的 串口通信线，9芯

RS-485数据线 是 双绞线或者屏蔽双绞线，232传输距离较近，485传输距离比较远，485是单工（向）通讯，232是双工（向）的。

通信编程都没有区别，都是按照RS232编程的，计算机没有485接口，需要用一个232转485的转换器就可以了。

串口的操作一般都通过四个步骤来完成：
1、打开串口
2、配置串口：对串口的波特率、数据位、停止位、校验码、等进行设置。
3、读写串口
4、关闭串口

        在linux下编写终端程序时，有规范模式，非规范模式（原始模式特殊的非规范模式）之分。不用于终端，而是在串口这种使用情况下，一般设置为原始模式（非规范的一种特殊情况）。但用read()函数，希望从串口接收指定的数量的字符时，往往接收到的实际字符数，都与指定的不同。如本人用read（）希望接收 10 bytes的数据，但实验后发现，分了几次才接收到，俩次接收2bytes ，两次接收3bytes。

 查阅相关资料得知：

      一般地串口的读写模式有直接模式和缓存模式，在直接模式下，串口的读写都是单字节的，也就是说一次的read或write只能操作一个字节；但是大部份串口芯片都支持缓存模式，缓存模式一般同时支持中断聚合和超时机制，也就是说在有数据时，当缓存满或者超时时间到时，都会触发读或写中断。写的时候可以将要操作的数据先搬到缓存里，然后启动写操作，芯片会自动将一连串的数据写出，在读的时候类似，一次读到的是串口芯片缓存里的数据。串口设备的缓存一般有限，一次能read到的最大字节数就是缓存的容量。所以串口芯片的缓存容量决定了你一次能收到的字节数。

     本人用一个usb转232来充当串口接收时，发现一次可以接收8个bytes。对于具体一次传输多少字节也不去追究了，总之通讯过程中无法保证一次发送的数据肯定是一次接收的，所以必须写代码来一次一次的接收，直到接收满足预定的为止，当然在此过程中得使用select/poll来避免超时接收。

      即从通讯的角度来说，接受方必须自己解决如何识别一个祯的问题.（操作串口相当于操作物理层，OSI／ISO模型中的第一层，解决祯同步问题是第二层的任务，所以我们需要自己搭一个第二层。也就是说：我们需要通过定义通讯协议，规定数据的内容自己分析什么时候收完了一次需要的数据。因为通讯过程中无法保证一次发送的数据肯定是一次接收的）

       简单的串口编程，一般设置成阻塞模式，便可以了。但是在大多数应用场合，把串口设置成阻塞模式是很不实用的，如read()时，如果没有数据发来，这程序一直会阻塞在这里（除非用多线程）。因此一般把其设置为非阻塞模式。一般是需要用串口读取指定长度的数据，但是read函数实际读取的数据长度，往往会与指定的不同，所以必须自己编写一个读写N字节数据的函数:很快想到用个循环，但是循环中必须有 ‘即使一直没有收到指定长度的数据但在一定时间后也必须跳出循环’的机制，否则就与阻塞模式的没有区别了（也就是让函数一直等，等到指定长度数据接收为止）。参考下APUE的程序清单14-11的readn（）函数，此函数看似很好，但是它不适合用于串口的读取，因为它一旦if(nread = read(fd, ptr, nleft) < 0) 就立刻会跳出循环，没有丝毫的时间上的容限，而串口的接收必然没有这么快，如若波特率为1200，是比较慢的。俩个字节传输的间隔，其都会被判断为错误而跳出。当然该函数对于读写文件是非常好用的。

ssize_t             /* Read "n" bytes from a descriptor  */
readn(int fd, void *ptr, size_t n)
{
 size_t  nleft;
 ssize_t  nread;

 nleft = n;
 while (nleft > 0) {
  if ((nread = read(fd, ptr, nleft)) < 0) {
   if (nleft == n)
    return(-1); /* error, return -1 */
   else
    break;      /* error, return amount read so far */
  } else if (nread == 0) {
   break;          /* EOF */
  }
  nleft -= nread;
  ptr   += nread;
 }
 return(n - nleft);      /* return >= 0 */
}

非阻塞I/O使我们的操作要么成功，要么立即返回错误，不被阻塞。
对于一个给定的描述符两种方法对其指定非阻塞I/O:
(1)调用open获得描述符，并指定O_NONBLOCK标志
(2)对已经打开的文件描述符，调用fcntl，打开O_NONBLOCK文件状态标志。
int flags，s为描述符

C/C++ code
flags = fcntl( s, F_GETFL, 0 ) )
fcntl( s, F_SETFL, flags | O_NONBLOCK )

 

 再次参考下APUE的tread() 和treadn（）函数，这组函数结合了select函数，使得在放弃之前，有了个时间来阻塞。有了一定的时间容限。例如把select中的tv.tv_sec = 1;这样就不会把 原本正常的俩个字节的时间间隔，误判为错误了。ssize_t

tread(int fd, void *buf, size_t nbytes, unsigned int timout)

{

       int                         nfds;

       fd_set                   readfds;

       struct timeval  tv;

 

       tv.tv_sec = timout;

       tv.tv_usec = 0;

       FD_ZERO(&readfds);

       FD_SET(fd, &readfds);

       nfds = select(fd+1, &readfds, NULL, NULL, &tv);

       if (nfds <= 0) {

              if (nfds == 0)

                     errno = ETIME;

              return(-1);

       }

       return(read(fd, buf, nbytes));

}

 ssize_t

treadn(int fd, void *buf, size_t nbytes, unsigned int timout)

{

       size_t      nleft;

       ssize_t     nread;

 

       nleft = nbytes;

       while (nleft > 0) {

         if ((nread = tread(fd, buf, nleft, timout)) < 0) {

                     if (nleft == nbytes)

                            return(-1); /* error, return -1 */

                     else

                            break;      /* error, return amount read so far */

             } else if (nread == 0) {

                     break;          /* EOF */

              }

              nleft -= nread;

              buf += nread;

       }

 return(nbytes - nleft);      /* return >= 0 */

}

实际应用如：

某个串口通信协议一帧为10个字节，linux 必须接收1帧后去解析该帧的命令。波特率1200 。在linux中必须有个读取一帧数据的函数，该函数不能‘一直等待接收10个字节’，而必须在一定时间内没有收到完整的一帧就放弃该帧，这样才能防止对方发送错误或者通信中的错误带来的问题。利用treadn()很好的配合该思路的实现。可以定时限为10ms。如果超过10ms（可以设置长点）这treadn()也会返回，这时判断如果实际收到的数据小于10，则丢弃即可。本人用1200的波特率，tv设置成了500us，工作的很好。

1、串口操作需要的头文件：

#include <stdio.h>         //标准输入输出定义
#include <stdlib.h>        //标准函数库定义
#include <unistd.h>       //Unix标准函数定义
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>          //文件控制定义
#include <termios.h>     //POSIX中断控制定义
#include <errno.h>        //错误号定义

2.打开串口

串口位于/dev中，可作为标准文件的形式打开，其中：
串口1 /dev/ttyS0
串口2 /dev/ttyS1
代码如下：

int fd;
fd = open(“/dev/ttyS0”, O_RDWR);
if(fd == -1)
{
    Perror(“串口1打开失败！”);
}
//else
    //fcntl(fd, F_SETFL, FNDELAY);

除了使用O_RDWR标志之外，通常还会使用O_NOCTTY和O_NDELAY这两个标志。
O_NOCTTY：告诉Unix这个程序不想成为“控制终端”控制的程序，不说明这个标志的话，任何输入都会影响你的程序。
O_NDELAY：告诉Unix这个程序不关心DCD信号线状态，即其他端口是否运行，不说明这个标志的话，该程序就会在DCD信号线为低电平时停止

3.设置波特率

最基本的串口设置包括波特率、校验位和停止位设置，且串口设置主要使用termios.h头文件中定义的termios结构，如下：
struct termios
{
   tcflag_t  c_iflag;   //输入模式标志
   tcflag_t  c_oflag;  //输出模式标志
   tcflag_t  c_cflag;  //控制模式标志
   tcflag_t  c_lflag;   //本地模式标志
   cc_t   c_line;              //line discipline
   cc_t   c_cc[NCC];    //control characters
}
代码如下：

int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300, B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {38400, 19200, 9600, 4800, 2400, 1200, 300, 38400, 19200, 9600, 4800, 2400, 1200, 300, };

void SetSpeed(int fd, int speed)
{
    int i;
    struct termios Opt;    //定义termios结构

    if(tcgetattr(fd, &Opt) != 0)
    {
        perror(“tcgetattr fd”);
        return;
    }
    for(i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
    {
        if(speed == name_arr[i])
        {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            if(tcsetattr(fd, TCSANOW, &Opt) != 0)
            {
                perror(“tcsetattr fd”);
                return;
            }
            tcflush(fd, TCIOFLUSH);
        }
    }
}

注意tcsetattr函数中使用的标志：
TCSANOW：立即执行而不等待数据发送或者接受完成。
TCSADRAIN：等待所有数据传递完成后执行。
TCSAFLUSH：Flush input and output buffers and make the change

4.设置数据位、停止位和校验位

以下是几个数据位、停止位和校验位的设置方法：（以下均为1位停止位）
8位数据位、无校验位：
Opt.c_cflag &= ~PARENB;
Opt.c_cflag &= ~CSTOPB;
Opt.c_cflag &= ~CSIZE;
Opt.c_cflag |= CS8;
7位数据位、奇校验：
Opt.c_cflag |= PARENB;
Opt.c_cflag |= PARODD;
Opt.c_cflag &= ~CSTOPB;
Opt.c_cflag &= ~CSIZE;
Opt.c_cflag |= CS7;
7位数据位、偶校验：
Opt.c_cflag |= PARENB;
Opt.c_cflag &= ~PARODD;
Opt.c_cflag &= ~CSTOPB;
Opt.c_cflag &= ~CSIZE;
Opt.c_cflag |= CS7;
7位数据位、Space校验：
Opt.c_cflag &= ~PARENB;
Opt.c_cflag &= ~CSTOPB;
Opt.c_cflag &= ~CSIZE;
Opt.c_cflag |= CS7;
代码如下：

int SetParity(int fd, int databits, int stopbits, int parity)
{
    struct termios Opt;
    if(tcgetattr(fd, &Opt) != 0)
    {
        perror("tcgetattr fd");
        return FALSE;
    }
   Opt.c_cflag |= (CLOCAL | CREAD);        //一般必设置的标志

    switch(databits)        //设置数据位数
    {
    case 7:
        Opt.c_cflag &= ~CSIZE;
        Opt.c_cflag |= CS7;
        break;
    case 8:
        Opt.c_cflag &= ~CSIZE;
        Opt.c_cflag |= CS8;
        berak;
    default:
        fprintf(stderr, "Unsupported data size.\n");
        return FALSE;
    }

    switch(parity)            //设置校验位
    {
    case 'n':
    case 'N':
        Opt.c_cflag &= ~PARENB;        //清除校验位
        Opt.c_iflag &= ~INPCK;        //enable parity checking
        break;
    case 'o':
    case 'O':
        Opt.c_cflag |= PARENB;        //enable parity
        Opt.c_cflag |= PARODD;        //奇校验
        Opt.c_iflag |= INPCK            //disable parity checking
        break;
    case 'e':
    case 'E':
        Opt.c_cflag |= PARENB;        //enable parity
        Opt.c_cflag &= ~PARODD;        //偶校验
        Opt.c_iflag |= INPCK;            //disable pairty checking
        break;
    case 's':
    case 'S':
        Opt.c_cflag &= ~PARENB;        //清除校验位
        Opt.c_cflag &= ~CSTOPB;        //??????????????
        Opt.c_iflag |= INPCK;            //disable pairty checking
        break;
    default:
        fprintf(stderr, "Unsupported parity.\n");
        return FALSE;    
    }

    switch(stopbits)        //设置停止位
    {
    case 1:
        Opt.c_cflag &= ~CSTOPB;
        break;
    case 2:
        Opt.c_cflag |= CSTOPB;
        break;
    default:
        fprintf(stderr, "Unsupported stopbits.\n");
        return FALSE;
    }

    opt.c_cflag |= (CLOCAL | CREAD);

    opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
 
    opt.c_oflag &= ~OPOST;
    opt.c_oflag &= ~(ONLCR | OCRNL);    //添加的
 
    opt.c_iflag &= ~(ICRNL | INLCR);
    opt.c_iflag &= ~(IXON | IXOFF | IXANY);    //添加的

    tcflush(fd, TCIFLUSH);
    Opt.c_cc[VTIME] = 0;        //设置超时为15sec
    Opt.c_cc[VMIN] = 0;        //Update the Opt and do it now
    if(tcsetattr(fd, TCSANOW, &Opt) != 0)
    {
        perror("tcsetattr fd");
        return FALSE;
    }

    return TRUE;
}

在用write发送数据时没有键入回车，信息就将发送不出去的情况，这主要是因为我们在输出输入时是按照 规范模式接受到回车或者换行才发送，而很多情况我们是不需要回车和换行的，这时，应当切换到行方式输入，设置options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);不经处理直接发送。

5.某些设置项
在第四步中我们看到一些比较特殊的设置，下面简述一下他们的作用。
c_cc数组的VSTART和VSTOP元素被设定成DC1和DC3，代表ASCII标准的XON和XOFF字符，如果在传输这两个字符的时候就传不过去，需要把软件流控制屏蔽，即：
Opt.c_iflag &= ~ (IXON | IXOFF | IXANY);
有时候，在用write发送数据时没有键入回车，信息就发送不出去，这主要是因为我们在输入输出时是按照规范模式接收到回车或换行才发送，而更多情况下我们是不必键入回车或换行的。此时应转换到行方式输入，不经处理直接发送，设置如下：
Opt.c_lflag &= ~ (ICANON | ECHO | ECHOE | ISIG);
还存在这样的情况：发送字符0X0d的时候，往往接收端得到的字符是0X0a，原因是因为在串口设置中c_iflag和c_oflag中存在从NL-CR和CR-NL的映射，即串口能把回车和换行当成同一个字符，可以进行如下设置屏蔽之：
Opt.c_iflag &= ~ (INLCR | ICRNL | IGNCR);
Opt.c_oflag &= ~(ONLCR | OCRNL);
6.读写串口
发送数据方式如下，write函数将返回写的位数或者当错误时为-1。
char buffer[1024];
int length;
int nByte;
nByte = write(fd, buffer, length);
读取数据方式如下，原始数据模式下每个read函数将返回实际串口收到的字符数，如果串口中没有字符可用，回叫将会阻塞直到以下几种情况：有字符进入；一个间隔计时器失效；错误发送。
在打开串口成功后，使用fcntl(fd, F_SETFL, FNDELAY)语句，可以使read函数立即返回而不阻塞。FNDELAY选项使read函数在串口无字符时立即返回且为0。
char buffer[1024];
int length;
int readByte;
readByte = read(fd, buffer, len);
注意：设置为原始模式传输数据的话，read函数返回的字符数是实际串口收到的字符数。Linux下直接用read读串口可能会造成堵塞，或者数据读出错误，此时可使用tcntl或者select等函数实现异步读取。用select先查询com口，再用read去读就可以避免上述错误。

 

也可以每个端口各open两个fd，一个rfd读方式打开(O_RDONLY|O_NDELAY),
，一个wfd写方式打开(O_WRONLY),
把你设置参数的函数只对wfd设置

7.关闭串口
串口作为文件来处理，所以一般的关闭文件函数即可：
close(fd);
8.目录
c_cflag用于设置控制参数，除了波特率外还包含以下内容：
EXTA         External rate clock
EXTB         External rate clock
CSIZE         Bit mask for data bits
CS5         5个数据位
CS6         6个数据位
CS7         7个数据位
CS8         8个数据位
CSTOPB         2个停止位（清除该标志表示1个停止位
PARENB         允许校验位
PARODD         使用奇校验（清除该标志表示使用偶校验）
CREAD         Enable receiver
HUPCL         Hangup (drop DTR) on last close
CLOCAL         Local line – do not change “owner” of port
LOBLK         Block job control outpu
c_cflag标志可以定义CLOCAL和CREAD，这将确保该程序不被其他端口控制和信号干扰，同时串口驱动将读取进入的数据。CLOCAL和CREAD通常总是被是能的。

c_lflag用于设置本地模式，决定串口驱动如何处理输入字符，设置内容如下：
ISIG            Enable SIGINTR, SIGSUSP, SIGDSUSP, and SIGQUIT signals
ICANON         Enable canonical input (else raw)
XCASE         Map uppercase \lowercase (obsolete)
ECHO         Enable echoing of input characters
ECHOE         Echo erase character as BS-SP-BS
ECHOK         Echo NL after kill character
ECHONL         Echo NL
NOFLSH         Disable flushing of input buffers after interrupt or quit characters
IEXTEN         Enable extended functions
ECHOCTL         Echo control characters as ^char and delete as ~?
ECHOPRT         Echo erased character as character erased
ECHOKE         BS-SP-BS entire line on line kill
FLUSHO         Output being flushed
PENDIN         Retype pending input at next read or input char
TOSTOP         Send SIGTTOU for background output

c_iflag用于设置如何处理串口上接收到的数据，包含如下内容：
INPCK         Enable parity check
IGNPAR         Ignore parity errors
PARMRK      Mark parity errors
ISTRIP         Strip parity bits
IXON         Enable software flow control (outgoing)
IXOFF         Enable software flow control (incoming)
IXANY         Allow any character to start flow again
IGNBRK         Ignore break condition
BRKINT         Send a SIGINT when a break condition is detected
INLCR         Map NL to CR
IGNCR         Ignore CR
ICRNL         Map CR to NL
IUCLC         Map uppercase to lowercase
IMAXBEL      Echo BEL on input line too long

c_oflag用于设置如何处理输出数据，包含如下内容：
OPOST         Postprocess output (not set = raw output)
OLCUC         Map lowercase to uppercase
ONLCR         Map NL to CR-NL
OCRNL         Map CR to NL
NOCR         No CR output at column 0
ONLRET      NL performs CR function
OFILL         Use fill characters for delay
OFDEL         Fill character is DEL
NLDLY         Mask for delay time needed between lines
NL0            No delay for NLs
NL1            Delay further output after newline for 100 milliseconds
CRDLY      Mask for delay time needed to return carriage to left column
CR0            No delay for CRs
CR1            Delay after CRs depending on current column position
CR2            Delay 100 milliseconds after sending CRs
CR3            Delay 150 milliseconds after sending CRs
TABDLY      Mask for delay time needed after TABs
TAB0            No delay for TABs
TAB1         Delay after TABs depending on current column position
TAB2         Delay 100 milliseconds after sending TABs
TAB3         Expand TAB characters to spaces
BSDLY      Mask for delay time needed after BSs
BS0         No delay for BSs
BS1         Delay 50 milliseconds after sending BSs
VTDLY      Mask for delay time needed after VTs
VT0         No delay for VTs
VT1         Delay 2 seconds after sending VTs
FFDLY      Mask for delay time needed after FFs
FF0         No delay for FFs
FF1         Delay 2 seconds after sending FFs

c_cc定义了控制字符，包含以下内容：
VINTR  Interrupt  CTRL-C
VQUIT  Quit    CTRL-Z
VERASE   Erase    Backspace (BS)
VKILL   Kill-line   CTRL-U
VEOF   End-of-file   CTRL-D
VEOL   End-of-line   Carriage return (CR)
VEOL2   Second    end-of-line Line feed (LF)
VMIN   Minimum number of characters to read  
VSTART   Start flow   CTRL-Q (XON)
VSTOP   Stop flow   CTRL-S (XOFF)
VTIME   Time to wait for data (tenths of seconds)

注意：控制符VTIME和VMIN之间有复杂的关系。VTIME定义要求等待的时间（百毫米，通常是unsigned char变量），而VMIN定义了要求等待的最小字节数（相比之下，read函数的第三个参数指定了要求读的最大字节数）。
如果VTIME=0，VMIN=要求等待读取的最小字节数，read必须在读取了VMIN个字节的数据或者收到一个信号才会返回。
如果VTIME=时间量，VMIN=0，不管能否读取到数据，read也要等待VTIME的时间量。
如果VTIME=时间量，VMIN=要求等待读取的最小字节数，那么将从read读取第一个字节的数据时开始计时，并会在读取到VMIN个字节或者VTIME时间后返回。
如果VTIME=0，VMIN=0，不管能否读取到数据，read都会立即返回。
 

// 
// test1.cc ends here
