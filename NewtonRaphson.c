#include <stdio.h>
#include <stdlib.h>

float f(float x){ // returns the y for y=f(x)
    return x*x*x - 7 * x*x + 14 * x - 6;
}

float df(float x){ // gives the derivative of f(x)
    return 3*x*x - 14 * x + 14;
}

float absolute(float x){ // returns the absolute value for float numbers
    return x<0?(-1*x):x;
}

int main(){
    int step = 0;
    float TOL = 0.001;
    float p = 0.5;
    float temp = f(p);
    printf("Give the step no:(TOL = 0.001)\n");
    scanf("%d", &step);
    printf("step:___p:___f(p):___\n"); 

    for(int i = 0; i < step; i++){
        printf("%d        %.3f   %.3f\n",i,p,temp);
        temp = f(p);
        p = p - temp / df(p);
        
        if(absolute(temp) < TOL){
            i++;
            printf("%d        %.3f   %.3f\n",i,p,temp);
            printf("\nf(p) is lower than TOL!!\np = %f" , p);
            return 0;
        }
    }

    return 0;

}