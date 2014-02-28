#include <stdio.h>

int main(int argc, char **argv){
  size_t SIZE = 256;
  long i;
  long long s;
  char b[SIZE];
  FILE *f;

  f = fopen(argv[1], "r");
  s = 0;
  i = 0;
  memset(b, SIZE, 0);
  while ( (fread(&b, , f) != NULL) ){
    s += atoi(b);
    memset(b, SIZE, 0);
  }
  fclose(f);
  printf("%ld\n", s);
}
