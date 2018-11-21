#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NAZWISKOS 1000
#define IMIES 1000

typedef struct {
    char *nazwisko;
    char *imie;
} osoba;

int main(void)
{
    osoba *ws_osoba = NULL;
    ws_osoba = malloc(sizeof ws_osoba);
    assert(ws_osoba != NULL);
    ws_osoba->imie = ws_osoba->nazwisko = NULL;
    ws_osoba->imie = malloc(IMIES * sizeof ws_osoba->imie);
    ws_osoba->nazwisko = malloc(NAZWISKOS * sizeof ws_osoba->nazwisko);
    assert(ws_osoba->imie != NULL && ws_osoba->nazwisko != NULL);
    scanf(" %s %s", ws_osoba->nazwisko, ws_osoba->imie);
    printf("Adres struktury: %p\n", ws_osoba);
    printf("Adres pola imie: %p\n", ws_osoba->imie);
    printf("Adres pola nazwisko: %p\n", ws_osoba->nazwisko);
    printf("Zawartosc pola imie: %s\n", ws_osoba->imie);
    printf("Zawartosc pola nazwisko: %s\n", ws_osoba->nazwisko);
    free(ws_osoba->imie);
    free(ws_osoba->nazwisko);
    free(ws_osoba);
    return 0;
}