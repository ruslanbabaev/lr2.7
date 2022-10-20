#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


int checking_the_polygon(int k, ...) {
    
    double ar[k*2];
    va_list ptr;
    va_start(ptr, k);
    
    for (int i = 0; i < k; i++) {
        ar[i] = va_arg(ptr, double);
    }
    
    double condition_1 = ((ar[1]-ar[3])*(ar[4]-ar[0])+(ar[2]-ar[0])*(ar[5]-ar[1])) * ((ar[1]-ar[3])*(ar[6]-ar[0])+(ar[2]-ar[0])*(ar[7]-ar[1]));
    double condition_2 = ((ar[5]-ar[7])*(ar[0]-ar[4])+(ar[6]-ar[4])*(ar[1]-ar[5])) * ((ar[5]-ar[7])*(ar[2]-ar[4])+(ar[6]-ar[4])*(ar[3]-ar[5]));
    double eps = 0.0001;
    
    if ((condition_1 > eps) && (condition_2 > eps)) {
            return 1;

    }
    
    va_end(ptr);
    return 0;
}

int main() {
    //пусть будет четырехугольник
    int k = 4; //количество углов
    double arr[k*2];
    printf("Является ли преугольник выпуклым?\n");

    
    for (int i = 0; i < (k*2); i+=2) {
        printf("Введите координату вершины в виде x y:\n");
        if (scanf("%lf %lf", &arr[i], &arr[i+1]) != 2) {
           printf("неправильный ввод\n");
           return 1;
        }
    }
    
    //проверим, четырехугольник ли это
   
    double cx,cy;
    double dd1,dd2,dd3,dd4;

    cx=(arr[0]+arr[2]+arr[4]+arr[6])/4;
    cy=(arr[1]+arr[3]+arr[5]+arr[7])/4;

    dd1 = sqrt(cx-arr[0])+sqrt(cy-arr[1]);
    dd2 = sqrt(cx-arr[2])+sqrt(cy-arr[3]);
    dd3 = sqrt(cx-arr[4])+sqrt(cy-arr[5]);
    dd4 = sqrt(cx-arr[6])+sqrt(cy-arr[7]);

    if ((dd1==dd2 && dd1==dd3 && dd1==dd4)) {
        printf("Это не четырехугольник!\n");
        return 1;
    }
    


    if (checking_the_polygon(8, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]) == 1) {
        printf("Четырехугольник выпуклый\n");
    } else
        printf("Четырехугольник невыпуклый\n");
    
    return 0;
}

