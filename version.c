/* version.c --- 
 * 
 * Description: 
 * Author: Hongyi Wu(吴鸿毅)
 * Email: wuhongyi@qq.com 
 * Created: 六 6月  4 20:52:19 2016 (+0800)
 * Last-Updated: 六 6月  4 20:54:40 2016 (+0800)
 *           By: Hongyi Wu(吴鸿毅)
 *     Update #: 2
 * URL: http://wuhongyi.cn */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  for (int i = 0; i < 3; ++i)
    {
      printf ("No. %d\n",i);
    }
  return 0;
}


/* version.c: 在函数‘main’中: */
/* version.c:17:3: 错误：‘for’ loop initial declarations are only allowed in C99 or C11 mode */
/*    for (int i = 0; i < 3; ++i) */
/*    ^ */
/* version.c:17:3: 附注：use option -std=c99, -std=gnu99, -std=c11 or -std=gnu11 to compile your code */

/* version.c ends here */
