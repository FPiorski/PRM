#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define NAZWISKOS 1000
#define IMIES 1000

typedef struct {
    double ocena_z_prm;
    int nr_indeksu;
} student;

int main(void)
{
    srand(time(NULL));
    int n = 0;
    scanf("%i", &n);
    student **tab = NULL;
    tab = malloc(n * sizeof tab);
    assert(tab != NULL);
    for (int i=0; i<n; ++i){
        tab[i] = NULL;
        tab[i] = malloc(sizeof tab[i]);
        assert(tab[i] != NULL);
        tab[i]->ocena_z_prm = (rand()/(double)(RAND_MAX)*2.5)+2;
        tab[i]->nr_indeksu = 293000 + rand()%1000;
    }
    for (int i=0; i<n; ++i)
        printf("Student nr %4i: Ocena z PRM: %4.2lf Nr indeksu: %i\n", i+1, tab[i]->ocena_z_prm, tab[i]->nr_indeksu);
    for (int i=0; i<n; ++i)
        free(tab[i]);
    free(tab);
    return 0;
}