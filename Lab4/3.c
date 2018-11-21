#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char imie[100], nazwisko[100];

    scanf("%s%s", imie, nazwisko);
    printf("Dlugosc imienia: %zu, dlugosc nazwiska: %zu\n",
            strlen(imie), strlen(nazwisko));

    for (char *i=imie; *i; ++i) //(*i) is equivalent to (*i != 0) and (*i != '\0')
        *i = toupper(*i);
    for (char *i=nazwisko; *i; ++i)
        *i = toupper(*i);
    printf("%s %s\n", imie, nazwisko);

    return 0;
}
