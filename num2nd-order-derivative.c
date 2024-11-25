#include <stdio.h> 

#include <math.h> 

  

double second_derivative_exact(double x) { 

    return -sin(x); 

} 

  

double second_derivative_approx(double (*f)(double), double x, double h) { 

    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h); 
} 

  

double f(double x) { 

    return sin(x); 

} 

  

double l2_error(double (*f_exact)(double), double (*f_approx)(double (*)(double), double, double), 

                double (*func)(double), double a, double b, double h) { 

    double error_sum = 0.0; 

    int n = (int)((b - a) / h); 

    for (int i = 1; i < n; i++) { 

        double x = a + i * h; 

        double exact = f_exact(x); 

        double approx = f_approx(func, x, h); 

        error_sum += pow(exact - approx, 2); 

    } 

    return sqrt(error_sum * h); 

} 

  

int main() { 

    double a = 0.0; 

    double b = M_PI; // [0, pi] 

    double h = 0.1;  

    printf("h\t\tL2 Error\n"); 

    while (h >= 0.0001) { 
        double error = l2_error(second_derivative_exact, second_derivative_approx, f, a, b, h); 

        printf("%lf\t%lf\n", h, error); 

        h /= 2; 

    } 

    return 0; 

} 
