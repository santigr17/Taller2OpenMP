#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


void saxpy(int n, int a, int * x, int * y)
{
  //#pragma omp parallel for  
  for (int i = 0; i < n; ++i)
      y[i] = a*x[i] + y[i];
}

int main (){
    double start_time, run_time;
    unsigned int size = 100000;
    int x[size];
    int y[size];
    for(unsigned int i=0; i<size; i++){
        x[i] = rand() % 25;
        y[i] = rand() % 25;
    }

    start_time = omp_get_wtime();
    saxpy(size, 5, x, y);
    run_time = omp_get_wtime() - start_time;
    printf("\n SAXPY, array size %d operated in %f seconds \n",size,run_time);
    return 0;
}



