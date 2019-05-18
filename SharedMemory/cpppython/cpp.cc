// cpp.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 5月 18 16:04:29 2019 (+0800)
// Last-Updated: 六 5月 18 16:11:36 2019 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 9
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int        id = 0;
  // char    *data = NULL;
  void    *data = NULL;
  FILE    *fp = NULL;
  int        totle_len = 0;
  int        len = 0;
  char    buf[1024] = {0};
    
  if (argc < 2)
    {
      printf("args too less\n");
      return 0;
    }
    
  id = shmget(123559, 21 * 1024 * 1024, IPC_CREAT | 0777);
  if (id < 0)
    {
      printf("get id failed\n");
      return 0;
    }
    
  data = shmat(id, NULL, 0);
  if (data == NULL)
    {
      printf("shamt failed\n");
      return 0;
    }
    
  fp = fopen(argv[1], "rb");
  if (fp == NULL)
    {
      printf("open %s failed\n", argv[1]);
      return 0;
    }
    
  while (totle_len <= 12 + 20 * 1024 * 1024)
    {
      len = fread(buf, 1, 1024, fp);
      if (len <= 0)
        {
	  break;
        }
      memcpy(data + totle_len, buf, len);
      totle_len += len;
    }

  fclose(fp);    
  return 0;
}

// 
// cpp.cc ends here
