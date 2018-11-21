#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MYEPS 1e-5

int oblRozwKwad(double a, double b, double c, double* t1, double* t2);
int obliczRozwDwukwad(double t1, double t2, double* x1, double* x2, double* x3, double* x4);
int sprawdzRozw(double a, double b, double c, double x);

int main(void)
{
    double a, b, c, t[2]={-1, -1}, x[4], xrozw;
    printf("Podaj wspolczynniki:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    oblRozwKwad(a, b, c, t, t+1);
    xrozw = obliczRozwDwukwad(t[0], t[1], x, x+1, x+2, x+3);
    for (int i=0; i<xrozw; ++i)
        printf("Rozwiazanie %i: %lf Czy poprawne: %s\n", i+1, x[i], sprawdzRozw(a, b, c, x[i])?"tak":"nie");
    if (xrozw == 0)
        printf("Brak rozwiazan!\n");
    return 0;
}

int oblRozwKwad(double a, double b, double c, double* t1, double* t2)
{
    double delta = b*b - 4*a*c;
    if (fabs(delta)<MYEPS){
        *t1 = (-1)*(b)/(2*a);
        return 1;
    } else if (delta<0){
        return 0;
    } else {
        *t1 = ((-1)*(b)+sqrt(delta))/(2*a);
        *t2 = ((-1)*(b)-sqrt(delta))/(2*a);
        return 2;
    }
}

int obliczRozwDwukwad(double t1, double t2, double* x1, double* x2, double* x3, double* x4)
{   
    if (t1<0){
        if (t2<0){
            *x1 = 0;
            *x2 = 0;
            *x3 = 0;
            *x4 = 0;
            return 0;
        } else {
            *x1 = sqrt(t2);
            *x2 = (-1) * (*x1);
            return 2;
        }
    } else {
        *x1 = sqrt(t1);
        *x2 = (-1) * (*x1);
        if (t2<0){
            *x3 = 0;
            *x4 = 0;
            return 2;
        } else {
            *x3 = sqrt(t2);
            *x4 = (-1) * (*x3);
            return 4;
        }
    }
    return -1000;
}

int sprawdzRozw(double a, double b, double c, double x)
{
    return (fabs(a*x*x*x*x+b*x*x+c)<MYEPS);
}
