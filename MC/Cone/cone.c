//Monte carlo stożek
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define OUTPUTFILE "wyniki.txt"

double norm(int n);

int main(void)
{
    srand(time(NULL));
    double r, h;
    printf("Podaj wysokość i promień stożka:\n");
    scanf("%lf%lf", &h, &r);
    FILE *fp = fopen(OUTPUTFILE, "w");
    for (int i=10; i<1000; ++i)
        fprintf(fp, "%i %lf\n", i, 4*r*r*h*norm(i));
    return 0;
}

double stoz(double x, double y, double z)
{
    return (sqrt(x*x + y*y) <= z);
}

double norm(int n)
{
    int sum = 0;
    for (int i=0; i<n; ++i){
        double x = (double)rand() / RAND_MAX,
               y = (double)rand() / RAND_MAX,
               z = (double)rand() / RAND_MAX;
        if (stoz(x, y, z))
            ++sum;
    }
    return (double) sum / n;
}
