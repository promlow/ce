#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int x, int y){
  if (x == y) return x;
  else if (x > y) return x;
  else return y;
}

int **lcs_arr(const char* a, const char *b){
  int m = strlen(a);
  int n = strlen(b);
  int L[m][n];
  for(int i=m; i>= 0; i--){
    for(int j=n; j >= 0; j--){
      if (a[i] == '\0' || b[j] == '\0') L[i][j] = 0;
      else if (a[i] == b[j]) L[i][j] = 1 + L[i+1][j+1];
      else L[i][j] = max(L[i+1][j], L[i][j+1]);
    }
    return L;
  }
}
 
const char* lcs(const char *a, const char *b){
  
}

int main(int argc, char **argv){
  size_t SIZE = 1024;
  char b[SIZE];
  char *token, *token1;
  FILE *f;

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    token = strtok(b, ";");
    token1 = token;
    token = strtok(NULL, ";");
    int **arr = lcs_arr(token1, token);

  }
  fclose(f);
}
