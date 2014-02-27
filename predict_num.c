#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 12
/* ceiling(log2(x)) */
int c_log2(long long x){
  int log = 0;
  if(x > 32767){
    x >>= 16;
    log += 16;
  }
  if(x > 127){
    x >>= 8;
    log += 8;
  }
  if(x > 7){
    x >>= 2;
    log += 2;
  }
  while(x > 0){
    x >>= 1;
    log++;
  }
  return log;
}

int main(int argc, char **argv){
  char b[SIZE];
  FILE *f;
  long long i, j;
  long long n;
  int max;
  size_t mem; 
  char *old;
  char *new;
  char c;

  printf("size_t: %d vs int: %d", sizeof(size_t), sizeof(int));

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    old = new = NULL;
    n = atoll(b);
    //length grows log2
    max = c_log2(n);
    //printf("\nsearch for char #%lld\n", n);
    //printf("max is %d\n", max);
    mem = 1;
    while (mem < (n/2)){
      mem <<= 1;
    }
    //printf("Allocating %d bytes\n", mem);
    old = calloc(mem, sizeof(char));
    new = calloc(mem, sizeof(char));
    if(old == NULL || new == NULL){
      printf("calloc failed\n");
      if(old) free(old);
      if(new) free(new);
      fclose(f);
      exit(-1);
    }
    c = old[0] = '0';
    //printf("before loop: %s\n", old);
    for(i = 1; i < max; i++){
      strncpy(new, old, strlen(old));
      //printf("new: %s\n", new);
      for(j=0; j<strlen(new);j++){
	if(new[j] == '0'){
	  new[j] = '1';
	}else if(new[j] == '1'){
	  new[j] = '2';
	}else{
	  new[j] = '0';
	}
	//printf("processing new: %s\n", new);
      }
      if(n < (strlen(old) + strlen(new))){
	j = strlen(old);
	j = n - j;
	c = new[j];
	//printf("found c: %c\n", c);
	break;
      }else{
	strncat(old, new, strlen(new));
	memset(new, 0, mem);
      }
    }
    printf("%c\n", c);

    //printf("dealloc begins\n");
    if(old != NULL){
      free(old);
      old = NULL;
    }
    //printf("freed old ");
    if(new != NULL){
      free(new);
      new = NULL;
    }
    //printf("and new\n");
  }

  fclose(f);
  exit(0);
}
