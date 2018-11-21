#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    double tab[10][10], sum = 0;

    srand( time(NULL) );

    for (int y=0; y<10; ++y){
        for (int x=0; x<10; ++x){
            printf("%lf ", tab[y][x] = (double)rand() / RAND_MAX);
            //type cast has higher priority than division
            if (y & 1) //equivalent to (y % 2 != 0)
                sum += tab[y][x];
        }
        printf("\n");
    }
    printf("%lf\n", sum);

    return 0;
}
