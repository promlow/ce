#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 12



int main(int argc, char **argv){
  char **A;
  char b[SIZE];
  FILE *f;
  long long i;
  long long n;
  int first, second, third, fourth, x, y;
  char **seq;

  //sequence goes 0, 1, 1, 2, 1, 2, 2, 0,
  //?             2, 0, 0, 1

  seq = malloc(4 * sizeof(char*));
  if(seq == NULL){
    printf("seq malloc failed\n");
    exit(-1);
  }
  A = malloc(3 * sizeof(char*));
  if(A == NULL){
    printf("A malloc failed\n");
    if(seq) free(seq);
    exit(-1);
  }
  for(i=0; i<3; i++){
    A[i] = malloc(2);
    if(A[i] == NULL){
      while(i >= 0){
	if(A[i] == NULL){
	  printf("A[%lld] failed\n", i);
	  free(A[i--]);
	}
      }
    }
  }

  //{ { '0', '1' }, { '1', '2' }, { '2', '0' } };
  A[0][0] = A[2][1] = '0';
  A[0][1] = A[1][0] = '1';
  A[1][1] = A[2][0] = '2';

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    n = atoll(b);
    printf("looking for: %lld\n", n);
    if (n == 0){
      printf("%c\n", '0');
      continue;
    }

    seq[0] = A[0];
    seq[1] = A[1];
    seq[2] = A[1];
    seq[3] = A[2];
    //    printf("%c, %c, %c, %c, %c, %c\n", seq[0][0], seq[0][1],seq[1][0],seq[1][1],seq[2][0],seq[2][1]);
/********
    for(i=1; i< n / 6; i++){
      first = i % 3;
      if(first > 1){
	second = third = 0;
	fourth = 1;
      }else{
	second = third = first + 1;
	if(third > 1){
	  fourth = 0;
	}else{
	  fourth = third + 1;
	}
      }
      //printf("%d, %d, %d, %d\n", first, second, third, fourth);
      seq[0] = A[first];
      seq[1] = A[second];
      seq[2] = A[third];
      seq[3] = A[fourth];
    }
*/
    x = (n % 6) % 3;
    y = x % 2;
    //    printf("x: %d, y: %d\n", x, y);
    printf("%c\n", seq[x][y]);
  }
  fclose(f);
  exit(0);
}
