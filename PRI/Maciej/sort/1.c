#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sort1(long int *tab, int dlug);
int sort2(long int *tab, int dlug);
int wypisz(long int *tab, int dlug);

int main(void) {
    int dlug;
    long int *tab;
    char s[10000], *er, c;
    do{
        printf("Wprowadz dlugosc tablicy: ");
        scanf("%s", s);
        dlug = strtol(s, &er, 10);
    } while (*er);
    tab = malloc(dlug * sizeof(long int));
    printf("Wprowadz %i elementow:\n", dlug);
    for (int i=0; i<dlug; ++i) {
        scanf("%s", s);
        tab[i] = strtol(s, &er, 10);
        if (*er)
            --i;
    }
    printf("1 wypisuje liczby posortowane rosnaco przez wybieranie, 2 wypisuje liczby posortowane malejaco przez wstawianie, q konczy prace programu\n");
    while ((c=getchar())!='q'){
        if (c=='1'){
            sort1(tab, dlug);
            wypisz(tab, dlug);
        }
        if (c=='2'){
            sort2(tab, dlug);
            wypisz(tab, dlug);
        }
    }
    return 0;
}


int sort1(long int *tab, int dlug)
{
    int in;
    for (int i=0; i<dlug; ++i){
        in = i;
        for (int j=i; j<dlug; ++j){
            if (tab[j] < tab[in])
                in = j;
        }
        int t = tab[in];
        for (int k=in; k>i; --k)
            tab[k]=tab[k-1];
        tab[i] = t;
    }
    return 0;
}


int sort2(long int *tab, int dlug)
{
    int in;
    for (int i=0; i<dlug; ++i){
        in = i;
        for (int j=i; j<dlug; ++j)
            if (tab[j] > tab[in])
                in = j;
        int tmp = tab[in];
        tab[in] = tab[i];
        tab[i] = tmp;
    }
    return 0;
}

int wypisz(long int *tab, int dlug)
{
    for(int i=0; i<dlug; ++i){
        printf("%li\n", tab[i]);
    }
    return 0;
}
