#include <stdio.h>

int main(void)
{
    int cd;
    char s[16];

    scanf("%s", s);

    for (char *d=s; *d; *(d++)-='0');

    cd  = s[0] + s[3] + s[5] + s[8] + s[10] + s[12];
    cd *= 3;
    cd += s[2] + s[4] + s[6] + s[9] + s[11];
    cd %= 10;
    if (cd)
        cd = 10 - cd;

    if (cd == s[14])
        printf("Correct UPC\n");
    else
        printf("Incorrect UPC\n");

    return 0;
}
