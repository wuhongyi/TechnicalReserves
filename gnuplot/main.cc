// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 7月 16 09:09:46 2016 (+0800)
// Last-Updated: 六 7月 16 10:46:14 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 19
// URL: http://wuhongyi.cn 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h> 
#include <pthread.h>
#include <time.h>

#define GNUPLOT_COMMAND  "gnuplot"
#define PLOT_DATA_FILE   "PlotData.txt"

typedef struct {
    char              Title[100];
    char              TraceName[100];
    char              Xlabel[100];
    char              Ylabel[100];
    int               Xautoscale;
    int               Yautoscale;
    float             Xscale;
    float             Yscale;
    float             Xmax;
    float             Ymax;
    float             Xmin;
    float             Ymin;
    int               NumTraces;
    int               TraceSize;
    double            TraceData[100];
} WDPlot_t;

int main(int argc, char *argv[])
{
  FILE *gnuplot = NULL;
  if ((gnuplot = popen("gnuplot", "w")) == NULL) // open the pipe
    return -1;

  WDPlot_t PlotVar;
  
  /* send some plot settings */
  fprintf(gnuplot, "set grid\n");
  fprintf(gnuplot, "set mouse\n");
  fprintf(gnuplot, "bind y 'set yrange [Ymin:Ymax]'\n");
  fprintf(gnuplot, "bind x 'set xrange [Xmin:Xmax]'\n");
  fflush(gnuplot);

  /* set default parameters */
  strcpy(PlotVar.Title, "");
  strcpy(PlotVar.Xlabel, "");
  strcpy(PlotVar.Ylabel, "");
  strcpy(PlotVar.TraceName, "");
  PlotVar.Xscale = 1.0;
  PlotVar.Yscale = 1.0;
  PlotVar.Xmax = 16384;
  PlotVar.Ymax = 16384;
  PlotVar.Xmin = 0;
  PlotVar.Ymin = 0;
  PlotVar.NumTraces = 0;

  FILE *fplot;
  fplot = fopen(PLOT_DATA_FILE, "w");
  
  for (int i = 0; i < 100; ++i)
    {
      fprintf(fplot, "%d %d\n", i,4*i*i);
    }
  // fprintf(fplot, "\n");
  fclose(fplot);



  fprintf(gnuplot, "set xlabel '%s'\n", PlotVar.Xlabel);
  fprintf(gnuplot, "set ylabel '%s'\n", PlotVar.Ylabel);
  fprintf(gnuplot, "set title '%s'\n", PlotVar.Title);
  fprintf(gnuplot, "Xs = %f\n", PlotVar.Xscale);
  fprintf(gnuplot, "Ys = %f\n", PlotVar.Yscale);
  fprintf(gnuplot, "Xmax = %f\n", PlotVar.Xmax);
  fprintf(gnuplot, "Ymax = %f\n", PlotVar.Ymax);
  fprintf(gnuplot, "Xmin = %f\n", PlotVar.Xmin);
  fprintf(gnuplot, "Ymin = %f\n", PlotVar.Ymin);
  
  fprintf(gnuplot, "set autoscale x\n");
  fprintf(gnuplot, "set autoscale y\n");
  fflush(gnuplot);

  
  fprintf(gnuplot, "plot ");
  fprintf(gnuplot, "'%s' using ($1*1.0):($2*1.0) title '%s' with step linecolor %d ", PLOT_DATA_FILE, PlotVar.TraceName, 1);

  
  fprintf(gnuplot, "\n"); 
  fflush(gnuplot);


  sleep(10);
  
  if (gnuplot != NULL)
    pclose(gnuplot);
  return 0;
}

// 
// main.cc ends here
