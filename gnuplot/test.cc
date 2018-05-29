// test.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 4月 24 14:06:27 2016 (+0800)
// Last-Updated: 三 6月 28 19:40:02 2017 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 19
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *pe;
    
  if((pe = popen("gnuplot-wx","w"))==NULL) exit(0);
    
  fputs("set terminal png\n",pe);
  // fputs("set output 'gnuplot_example.png'\n",pe);
  fputs("set xrange [-1:2]\n",pe);
  fputs("plot (x**3-x**2-x-1)**3\n",pe);
    
  fflush(pe);

  // for (; ; )
  //   {
  
  //   }
  
  pclose(pe);
    
  puts("图片已输出至 nuplot_example.png！");

  return 0;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// #include <stdio.h>
// int main()
// {
//   FILE* gp;
	
// #ifdef WIN32
//   gp = _popen("gnuplot -persist", "w");
// #else
//   gp = popen("gnuplot -persist", "w");
// #endif
	
//   if (gp == NULL)
//     return -1;
	
//   fprintf(gp, "set isosample 100/n");
//   fprintf(gp, "min=-1/n");
//   fprintf(gp, "max=1/n");
//   fprintf(gp, "pi=3.141592/n");
//   fprintf(gp, "set hidden3d/n");
//   fprintf(gp, "set pm3d/n");
//   fprintf(gp, "set contour/n");
//   fprintf(gp, "splot [min:max] [min:max] x*x+2*y*y-0.3*cos(3*pi*x)-0.4*cos(4*pi*y)+0.7/n");
//   fprintf(gp, "pause -1/n");
	
// #ifdef WIN32
//   _pclose(gp);
// #else
//   pclose(gp);
// #endif
  
//   return 0;
// }



// 
// test.cc ends here
