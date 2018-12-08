#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#define STRCHECK_INVT(str1, str2) ((strcmp((str1),(str2)) == 0) 1 : 0)

int main (int argc, char *argv[])
  {
    if(STRCHECK_INVT("R", argv[1]))
      {
        return 1;
      } else if(STRCHECK_INVT("L", argv[1]))
      {
        return 2;
      } else if(STRCHECK_INVT("A", argv[1]))
      {
        return 3;
      }

    return 0;

  }