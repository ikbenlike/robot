#define Bool int
#define False 0
#define True 1
#include "stdlib.h"
#include "stdio.h"
#define END '<'
#define XML "data/data.xml"

int read(FILE* fileToRead) {
    Bool isminus = 0;
    Bool isokay = 0;
    int result_number = 0;
    while (True) {
        char char_ = fgetc(fileToRead);
        if (char_ == END) break; isokay++;
        result_number = 012 * result_number;
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

int main()
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
printf("%d %d %d", x, y, d);
}
