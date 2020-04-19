#include <stdlib.h>
#include <stdio.h>

float f(float x){
    return (x*x*x) - (2.0*x*x) + 5.0;
}

int g(int x){
    if(x == 1) return -4;
    else if(x == 2) return 5;
    else if(x == 3) return 26;
    else if(x == 4) return 65;
}

int main(){

    float result;
    printf("1.\n");

    printf("x = 1 -> %f \n", (1.0/2.0) * ( -3 * g(1) + 4 * g(2) - g(3)));
    printf("x = 2 -> %f \n", (1.0/2.0) * ( -1 * g(1) + g(3) ));
    printf("x = 3 -> %f \n", (1.0/2.0) * (-1 * g(2) + g(4) ));
    printf("x = 4 -> %f \n", (1.0/2.0) * ( g(2) - 4 * g(3) + 3 * g(4) ));

    printf("2.\n");
    result = (3.0 / 8.0) * ( f(0.0) + 3*f(1.0) + 3*f(2.0) + f(3.0) );
    printf("%f", result);
    
}