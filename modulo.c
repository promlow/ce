#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mod(int a, int n){
  if(n == 0) return -1;
  //https://en.wikipedia.org/wiki/Modular_arithmetic
  return a - (floor(a/n)) * n;
}

int main(int argc, char **argv){
  size_t SIZE = 15;
  char b[SIZE];
  char *token;
  FILE *f;
  int a, n;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    token = strtok(b, ",");
    a = atoi(token);
    token = strtok(NULL, ",");
    n = atoi(token);
    printf("%d\n", mod(a,n));
  }    
  fclose(f);
}
