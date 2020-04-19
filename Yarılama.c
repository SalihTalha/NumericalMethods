#include <stdio.h>
#include <stdlib.h>

float f(float x){
    return x*x*x - 7 * x*x + 14 * x - 6;
}

float absolute(float x){
    return x<0?(-1*x):x;
}

int main(){
    float a = 0;
    float b = 1;
    int step = 0;
    float TOL = 0.001;
    float temp, p;
    printf("Give the step no:(TOL = 0.001)\n");
    scanf("%d", &step);
    // I can just say step = 100000 but this code is more user friendly
    printf("step:___a:___b:___p:___f(p):___\n"); 

    for(int i = 0; i < step; i++){
        p = (b+a)/2;
        temp = f(p);
        printf("%d    %.3f %.3f %.3f %.3f\n", i , a, b, p, temp);
        
        if(temp > 0){
            b = p;
        }else if(temp < 0){
            a = p;
        }else{
            printf("\n!! Exact match with the root:%f ", p);
            break;
        }
        if(absolute(temp) < TOL){
            printf("\nf(p) is lower than TOL!!");
            return 0;
        }
    }

    return 0;

}