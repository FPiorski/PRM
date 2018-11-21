//http://eduinf.waw.pl/inf/alg/004_int/0003.php
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integral(int n, double left, double right, double a, double b, double c);

int main(void)
{
    double in[5];
    char *ins[5] = {"wspolczynnik a",
                    "wspolczynnik b",
                    "wspolczynnik c",
                    "lewa granice calkowania",
                    "prawa granice calkowania"};
    char s[100], *er;
    for (int i=0; i<5; ++i){
        printf("Wprowadz %s:\n", ins[i]);
        scanf("%s", s);
        in[i] = strtod(s, &er);
        if (*er){
            printf("Blednie wprowadzone dane!\n");
            --i;
        }
    }
    if (in[3] > in[4]){
        printf("\n\nUWAGA! Lewa granica większa od prawej, wynaczona wartosc "
               "może byc przeciwnoscia spodziewanej!\n\n");
    }
    printf("Calka z (%.3lf*cos(%.3lf*x)+%.3lf)*dx od %.3lf do %.3lf obliczona "
           "metoda trapezow (dla n trapezow) to w zaleznosci od n:\n", in[0],
            in[1], in[2], in[3], in[4]);
    for (int n=3; n<100000; n*=1.35)
        printf("%i: %.5lf\n", n, integral(n, in[3], in[4], in[0], in[1], in[2]) );
    return 0;
}

double f(double x, double a, double b, double c)
{
    return a*cos(b*x)+c;
}

double integral(int n, double left, double right, double a, double b, double c)
{
    double dx = (right - left) / n, sum = 0, x1, x2;
    for (int i=0; i<n; ++i){
        x1 = left + (double)i / n * (right - left);
        x2 = left + (double)(i+1) / n * (right - left);
        sum += (f(x1,a,b,c) + f(x2,a,b,c)) / 2 * dx;
    }
    return sum;
}
