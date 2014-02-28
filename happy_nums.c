#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int happy(int x){
  char s[15];
  char str[2];
  char c;
  int i;
  int j;
  int sq;

  if (x < 1){
    return -1;
  }
  sprintf(s, "%d", x);

  while(sq != 1 && sq != 4){
    i = 0;
    sq = 0;
    while ( (c = s[i++]) != '\0'){
      str[0] = c;
      str[1] = '\0';
      j = atoi(str);
      sq += j * j;
    }
    sprintf(s, "%d", sq);
  }
  if (sq == 1) return 1;
  else return 0;
}

int main(int argc, char **argv){
  size_t SIZE = 15;
  char b[SIZE];
  FILE *f;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    int x = atoi(b);
    int n = happy(x);
    if (n > -1) {
      printf("%d\n", n);
    }
  }    
  fclose(f);
}
