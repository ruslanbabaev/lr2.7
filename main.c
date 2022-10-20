#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


double degree_polynomial(int k, ...) {
    //по схеме Горнера
    double all_a[k+1]; //массив коэффициентов
    double result = 0;
    va_list ptr;
    va_start(ptr, k);
    double x = va_arg(ptr, double);
    for(int i = 0; i < k; i++)
            all_a[i] = va_arg(ptr, double);

    result = ((((all_a[0]*x + all_a[1])*x + all_a[2])*x + all_a[3])*x + all_a[4])*x + all_a[5];
    va_end(ptr);
    return result;
}

int main() {
    double x;
    int n = 5;
    //пусть степень многочлена будет 5
    printf("Введите точку, в которой определяется значение многочлена: ");
    if (scanf("%lf", &x) != 1) {
       printf("Ошибка ввода. Возможно, вы ввели не число\n");
       return 1;
    }
    
    double arr[n+1];
    
    printf("Введите коэффициенты, с каждой новой строки:\n");
    for (int i = 0; i < (n+1); i++) {
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Ошибка ввода. Возможно, вы ввели не число\n");
            return 1;
        }
    }
    printf("Значение многочлена:\n");
    printf("%.2f\n", degree_polynomial(6, x, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]));
    
    return 0;
}
