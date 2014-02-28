#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 16

int main(int argc, char **argv){
  size_t SIZE = 15;
  char b[SIZE];
  FILE *f;
  int start, len, sum, digit, pow;
  int i,j;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE, f) != NULL) ){
    start = atoi(b);
    len = strlen(b) - 1; //ignore \n
    sum = 0;
    for(i=0; i<len; i++){
      digit = b[i] - 48; //assumes ASCII
      //printf("digit: %d\n", digit);
      pow = digit;
      for(j=1; j<len; j++){
	pow *= digit;
      }
      sum += pow;
    }
    //printf("start %d, sum %d\n", start, sum);
    if ( sum == start ){
      printf("True\n");
    }else{
      printf("False\n");
    }
  }
  fclose(f);
  exit(0);
}
