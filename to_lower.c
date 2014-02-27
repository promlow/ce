#include <stdio.h>

int main(int argc, char **argv){
  size_t SIZE = 256;
  char b[SIZE];
  FILE *f;
  int i;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    i = 0;

    while( b[i] != '\0' ){ //Assumes ASCII encoding
      if (b[i] <= 'Z' && b[i] >= 'A')
	b[i] += ' ';//i.e., 32

      i++;
    }
    printf("%s", b);
  }
  fclose(f);
}
