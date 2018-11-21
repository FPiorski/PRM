#define _DEFAULT_SOURCE
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define ENDSTR "BUM!"
#define RCOL 3.0

struct buf {
    char *data;
    int w, h;
};

int initBuf(struct buf *scr);
int freeBuf(struct buf *scr);
int clearScreen(void);
int pSet(struct buf *scr, int x, int y, char c);
int printWorld(struct buf *scr);
int delay(int ms);

int main(void)
{
    srand(time(NULL));
    clearScreen();
    struct buf scr;
    initBuf(&scr);
    double x1p = rand() % (scr.w/2) + scr.w/4.0,
           y1p = rand() % (scr.h/2) + scr.h/4.0,
           x2p = rand() % (scr.w/2) + scr.w/4.0,
           y2p = rand() % (scr.h/2) + scr.h/4.0,
           x1 = x1p, y1 = y1p,
           x2 = x2p, y2 = y2p,
           ang = (double)rand()/(RAND_MAX)*2*M_PI,
           t = 0;
    int b = 1;
    while (b){
        if (pSet(&scr, x1, y1, 'O') || pSet(&scr, x2, y2, '*')) 
            b = 0;
        if ( sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ) < RCOL){
            for (unsigned int i=0; i<strlen(ENDSTR); ++i)
                scr.data[i + scr.w/2 - strlen(ENDSTR) 
                           + (scr.h/2)*scr.w] = ENDSTR[i];
            b = 0;
        }
        printWorld(&scr);
        delay(50);
        pSet(&scr, x1, y1, ' ');
        pSet(&scr, x2, y2, ' ');
        x1 = x1p + 1.8*t*cos(t);
        y1 = y1p + t*sin(t);
        x2 = x2p + 2*t*cos(ang);
        y2 = y2p + 3*t*sin(ang);
        t += 0.15;
    }
    freeBuf(&scr);
    return 0;
}

int initBuf(struct buf *scr)
{
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);
    scr->w = win.ws_col;
    scr->h = win.ws_row;
    scr->data = malloc(scr->w * scr->h);
    memset(scr->data, ' ', scr->w * scr->h);
    return 0;
}

int freeBuf(struct buf *scr)
{
    free(scr->data);
    return 0;
}

int clearScreen(void)
{
    return system("tput clear");
}

int pSet(struct buf *scr, int x, int y, char c)
{
    if ((x < 0) || (x >= scr->w) || (y < 0) || (y >= scr->h))
        return 1;
    scr->data[x+y*scr->w] = c;
    return 0;
}

int printWorld(struct buf *scr)
{
    for (int y=0; y<scr->h; ++y)
        for (int x=0; x<scr->w; ++x)
            putchar(scr->data[x+y*scr->w]);
    return fflush(stdout);
}

int delay(int ms)
{
    return usleep(ms * 1000);
}
