#include <stdio.h>

double absl(double x){
    return x>0?x:(-1*x);
}

int main(){
    double x = 0.0;
    printf("Give the x:");
    scanf("%lf", &x);
    double points[4];
    double values[4];
    double lag[4];
    double results[4];
    double tP, tFP; // temp point and temp f(point)
    // get numbers from VERI.txt
    FILE * fPtr;

    if( (fPtr = fopen("VERI.txt", "r")) == NULL ){
        printf("Cannot read file!");
    }
    else{
        
        printf("p\t\tf(p)\n");
        for(int i = 0; i < 4; i++){
            fscanf(fPtr, "%lf %lf \n", &tP, &tFP);
            points[i] = tP;
            values[i] = tFP;
            printf("%lf, %lf \n", points[i] , values[i]);
        }

        printf("Lagrange Numbers:\n");
        for(int i = 0; i < 4; i++){ 
            lag[i] = 
            (x-points[(i+1) % 4]) * 
            (x-points[(i+2) % 4]) * 
            (x-points[(i+3) % 4]) / 
            ((points[i] - points[(i+1) % 4]) * (points[i] - points[(i+2) % 4]) * (points[i] - points[(i+3) % 4]));
            printf("Lagrange(3,%d) = %lf\n",i,lag[i]);
            results[i] = lag[i] * values[i];
        }
        double res =results[0]+results[1]+results[2]+results[3]; 
        printf("Final result: %lf + %lf + %lf + %lf = %lf",results[0],results[1],results[2],results[3], res);

    }


    fclose(fPtr);
    return 0;
}