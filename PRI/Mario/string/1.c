#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SDEFSIZE 10

typedef struct string_t {
    char *data;
    size_t cur, max;
} string;

int sInit(string *s);
int sFree(string *s);
int sZero(string *s);
int sPushBack(string *s, char c);
int sGetWord(string *s);
int sGetLine(string *s);

int main(void)
{
    string s;
    sInit(&s);
    sGetWord(&s);
    printf("%s\n", s.data);
    sGetLine(&s);
    printf("%s\n", s.data);
    sFree(&s);
    return 0;
}

int sInit(string *s){
    s->max = SDEFSIZE;
    s->cur = 1;
    if ( (s->data = malloc(s->max)) == NULL ){
        perror("Can't allocate memory\n");
        return 1;
    }
    *(s->data) = 0;
    return 0;
}

int sFree(string *s){
    free(s->data);
    return 0;
}

int sZero(string *s){
    s->cur = 1;
    *(s->data) = 0;
    return 0;
}

int sPushBack(string *s, char c){
    if (s->cur < s->max){
        s->data[s->cur-1] = c;
        s->data[s->cur++] = 0;
    } else {
        s->max *= 2;
        char *tmp = realloc(s->data, s->max);
        if (tmp == NULL){
            perror("Can't reallocate memory\n");
            s->max /= 2;
            return 1;
        } else
            s->data = tmp;
        sPushBack(s, c);
    }
    return 0;
}

int sGetWord(string *s){
    sZero(s);
    char c;
    while (!isspace(c=getchar()))
        if (sPushBack(s, c))
            ungetc(c, stdin);
    return 0;
}

int sGetLine(string *s){
    sZero(s);
    char c;
    while ((c=getchar()) != '\n')
        if (sPushBack(s, c))
            ungetc(c, stdin);
    return 0;
}
