#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char **argv){
  char b[SIZE];
  FILE *f;
  int n;
  int x, y;
  int p1, p2;
  int b1, b2;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    n  = atoi(strtok(b, ","));
    p1 = atoi(strtok(NULL, ","));
    p2 = atoi(strtok(NULL, ","));

    b1 = 1 << (p1 - 1);
    b2 = 1 << (p2 - 1);

    x = n & b1;
    y = n & b2;

    if ( x && y ){
      printf("true\n");
    }else if ( x == 0 && y == 0 ){
      printf("true\n");
    }else{
      printf("false\n");
    }
  }
  fclose(f);
}
