#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int tab[10][10] = {{0}}, sump = 0, sumn = 0;

    srand( time(NULL) );

    for (int y=0; y<10; ++y){
        for (int x=0; x<10; ++x){
            printf("%i ", tab[x][y] = rand() % 10);
            if (tab[x][y] & 1) //equivalent to (tab[x][y] % 2 != 0)
                sumn += tab[x][y];
            else
                sump += tab[x][y];
        }
        printf("\n");
    }

    printf("%i %i\n", sump, sumn);

    return 0;
}
