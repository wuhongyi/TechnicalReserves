// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 四 3月 24 13:33:59 2016 (+0800)
// Last-Updated: 五 4月 22 18:42:15 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 10
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int btod(char *bstr);       //二进制转十进制
int dtob(int d, char *bstr);    //十进制转二进制
 
int main(int argc, char **argv)
{
    char bstr[64];
    bzero(bstr, sizeof(bstr));
    int d = 0;
 
    printf("二进制数: ");
    scanf("%s", bstr);
    if ((d = btod(bstr)) < 0)
        printf("输入有误\n");
    else
        printf("二进制 %s 转 十进制为 %d\n", bstr, d);
 
    d = 0;
    bzero(bstr, sizeof(bstr));
 
    printf("十进制数: ");
    scanf("%d", &d);
    if ((dtob(d, bstr)) < 0)
        printf("输入有误\n");
    else
        printf("十进制 %d 转 二进制为 %s\n", d, bstr);


    unsigned int gain = 1 << 14;
    int count = 0;
    gain = gain >> 8;
    while(gain > 1)
      {
	gain = gain >> 1;
	count++;
      }
    printf("\n  %ld  %d\n",gain,count);
    
    return 0;
}
 
/**--------------------
 * @brief 十进制转二进制
 *
 * @param bstr 二进制字符串，不大与32位
 *
 * @return  出错返回-1，成功返回十进制数
 --------------------*/
int btod(char *bstr)
{
    int d = 0;
    unsigned int len = strlen(bstr);
 
    if (len > 32)
        return -1;  //数位过长
    len--;
 
    int i = 0;
    for (i = 0; i <= len; i++)
    {
        d += (bstr[i] - '0') * (1 << (len - i));
    }
 
    return d;
}
 
 
/**--------------------
 * @brief 十进制转二进制
 *
 * @param d 十进制数，输入
 * @param bstr 二进制字符串，输出
 *
 * @return 出错返回-1，成功返回字符串长度
 --------------------*/
int dtob(int d, char *bstr)
{
    if (d < 0)
        return -1;
 
    int mod = 0;
    char tmpstr[64];
    bzero(tmpstr, sizeof(tmpstr));
    bzero(bstr, sizeof(bstr));
 
    int i = 0;
    while (d > 0)
    {
        mod = d % 2;
        d /= 2;
        tmpstr[i] = mod + '0';
        i++;
    }
 
    //复制字符串
    unsigned int len = strlen(tmpstr);
    for (i = 0; i < len; i++)
    {
        bstr[i] = tmpstr[len - i - 1];
    }
 
    return (int)len;
}

// 
// main.cc ends here
