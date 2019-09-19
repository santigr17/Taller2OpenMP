#include <stdio.h>
#include <math.h>
#include <omp.h>

//#define pi 3.14159265


int fact(int x){
    if(x<2){
        return 1;
    }
    else
    {
        return x*fact(x-1);
    }
    
}

int main(){
    double start_time, run_time;
    const int x = 1; 
    float cos = 0;
    float sub_cos;
    start_time = omp_get_wtime();

    #pragma omp parallel for shared(cos) //private(x, fact, sub_cos)
    for(unsigned int n = 0; n < 17; n++)
    {
        sub_cos =  (pow(-1,n) * pow(x,2*n))/fact(2*n);
        cos += sub_cos;
        
    }
    run_time = omp_get_wtime() - start_time;
    printf("Seconds %f Cos(1): %f \n",run_time, cos);  

    return 1;

}