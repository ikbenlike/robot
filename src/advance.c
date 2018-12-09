#include "stdlib.h"
#include "stdio.h"
#define XML "data/data.xml"

int main()
{
FILE * f = fopen(XML, "r");
printf("alive\n");
int x,y,d;
char coor;
char mode;
while(!0) {
    char c = fgetc(f);
    if (c==EOF) goto end;
    if (c=='X') coor=c; mode='w';
    if (c=='Y') coor=c; mode='w';
    if (c=='>') mode='r';
    if (c=='d') coor=c;
    if (mode==r) {
        int v = read(f);
        if ( v == 0xBAD ) ; else {
            if (coor=='X')
                x=v;
            if (coor=='Y')
                y=v;
            if (coor=='D');
                d=v;
        }
    }
}
end:;
}
