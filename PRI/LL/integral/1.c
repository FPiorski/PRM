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

double fi(int i, int n, double left, double right, double a, double b, double c)
{
    double x = left + (double)i / n * (right - left);
    return a*cos(b*x)+c;
}

double integral(int n, double left, double right, double a, double b, double c)
{
    double dx = (right - left) / n, sum = 0;
    for (int i=1; i<n; ++i)
        sum += fi(i, n, left, right, a, b, c);
    sum += (fi(0, n, left, right, a, b, c) + fi(n, n, left, right, a, b, c)) / 2;
    return sum * dx;
}
