#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 16

int main(int argc, char **argv){
  size_t SIZE = 15;
  char b[SIZE];
  char *t1, *t2;
  int end;
  int start;
  int total;
  int i;
  FILE *f;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE, f) != NULL) ){
    t1 = strtok(b, ",");
    t2 = strtok(NULL, ",");
    end = atoi(t1);
    start = atoi(t2);
    total = start;

    for(i=2; total < end; i++){
      total = i * start;
    }
    printf("%d\n", total);

  }
  fclose(f);
  exit(0);
}
