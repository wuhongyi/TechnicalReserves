// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 5月 10 20:06:48 2016 (+0800)
// Last-Updated: 二 5月 10 20:32:30 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 5
// URL: http://wuhongyi.cn 

// g++ main.cc -lreadline -o 123
// gnu readline

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char *argv[])
{
  char *input,shell_prompt[100];
  rl_bind_key('\t', rl_complete);

for (; ; )
  {
    snprintf(shell_prompt, sizeof(shell_prompt), "%s:%s > ", getenv("USER"),getcwd(NULL, 1024));

    input = readline(shell_prompt);

    if(!input) break;

    add_history(input);
    printf(" %s \n", input);
    
    free(input);
  }

  
  return 0;
}



// 
// main.cc ends here
