#include <stdio.h>

char *mies[12] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien"};

int main(void)
{
    char data[100]; //11 would suffice
    scanf(" %s", data);
    for (char *i=data; *i; ++i)
        *i -= '0';
    printf("%i %s %i\n", data[0]*10 + data[1], mies[data[3]*10 + data[4] - 1], data[6]*1000 + data[7]*100 + data[8]*10 + data[9]);
    return 0;
}
