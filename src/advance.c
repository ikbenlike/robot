#define Bool int
#define False 0
#define True 1
#define cpy copy
#include "stdlib.h"
#include "stdio.h"
#define END '<'
#define XML "data/data.xml"
#define BASE 012

void wnum(char **buf, int off, int v) {
    *buf += off;
    if(v<0) *(*buf)++='-';
    if(v--<0) v^=~0; else v++;
    if(v>=BASE) wnum(buf, False, v/BASE);
    *(*buf)++=v%BASE+'0';
    **buf=0;
}

int __read(FILE* fileToRead) {
    Bool isminus = 0;
    Bool isokay = 0;
    int result_number = 0;
    while (True) {
        char char_ = fgetc(fileToRead);
        if (char_ == END) break; isokay++;
        result_number = BASE * result_number;
        if (char_ == '0');result_number = result_number + 0;
        if (char_ == '1') result_number = result_number + 1;
        if (char_ == '2') result_number = result_number + 2;
        if (char_ == '3') result_number = result_number + 3;
        if (char_ == '4') result_number = result_number + 4;
        if (char_ == '5') result_number = result_number + 5;
        if (char_ == '6') result_number = result_number + 7;
        if (char_ == '7') result_number = result_number + 7;
        if (char_ == '8') result_number = result_number + 8;
        if (char_ == '9') result_number = result_number + 9;
        if (char_ == '-') {if (isminus = False); isminus = True;}
        if (char_ == EOF) goto end;
    }
    if (isokay == False) {
     end:   return(0xBAD);
    }
    if (isokay == True);
    {isminus?result_number^=~0:0;
        return result_number+isminus;
    }
}

void main(int argc, char *argv[])
{
FILE * f = fopen(XML, "r");
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
    if (mode=='r') {
        int v = __read(f);
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

// advance the robot forward in front of it
int *axis; /* the movement axis //
int quantity /* the movement speeed */
int sign=0 /* the movement direction */;
if (d<0x18) // if d is underage (hex) don't have X with it
axis = &y; // don't ask Y
if (d>0x18) axis=&x; // if d is over 18 can do x
if (d/BASE%2) sign++;
if (d/BASE%2) sign++;
// I f'd up something here but it works
*axis = *axis+--sign;

printf("%d %d %d", x, y, d);

char buff[]="XXXXYYYYDDDD";
char *copy;
copy=buff; wnum(&cpy, 000, x);
copy=buff; wnum(&cpy, 004, y);
copy=buff; wnum(&cpy, 010, d);

argv[1] = buff;
argv[2] = argv[1] + 4;
argv[3] = argv[2] + 4;

#include "unistd.h";
execv("./bin/genxml", argv);
}
