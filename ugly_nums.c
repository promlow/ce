#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int is_ugly(long long n){
  printf("ugly (%lld)\n", n);
  return
    (n == 0)     ||
    (n % 3 == 0) || 
    (n % 5 == 0) || 
    (n % 7 == 0);
}

void chomp(char *s){
  int last_char = strlen(s) - 1;
  if ( s[last_char] == '\n'){
    s[last_char] = '\0';
  }
}

char *substring(char *s, int start, int len){
  char *sub = malloc(len + 1);
  memcpy( sub, s, len);
  sub[len] = '\0';
  return sub;
}

long long perm(int *count, int index, char *s){
  long long n;
  char *left;
  if (strlen(s) == 0) return 0;
  if (strlen(s) == 1) {
    if (index == 0) { //deal with single digits
      if ( is_ugly( atoll( s ) ) )
	(*count)++;
    }
    return atoll(s);
  }
  n = 0;
  printf("perm (%d, %d, %s)\n", *count, index, s);
  for(int i=index; i < strlen(s); i++){
    left = substring(s, i, index);
    //printf("left %s\n", left);
    n = atoll(left);
    n += perm(count, i + 1, left);
    if( is_ugly(n) ){
      (*count)++;
    }
    left = substring(s, i, strlen(s) - i);
    n = atoll(left);
    n -= perm(count, i + 1, left);
    if( is_ugly(n) ){
      (*count)++;
    }
  }
  printf("%lld\n", n);
  return n;  
}

int main(int argc, char **argv){
  char b[SIZE];
  FILE *f;
  int ugly;

  if( argc < 2){
    printf("supply a filename\n");
    exit(-1);
  }
  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE, f) != NULL) ){
    ugly = 0;
    chomp(b);
    perm(&ugly, 0, &b[0]);
    printf ("RESULT: %d\n", ugly);
  }
  fclose(f);
  exit(0);
}
