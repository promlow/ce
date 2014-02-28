#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *e1, const void *e2){
  double f1 = *((double*)e1);
  double f2 = *((double*)e2);
  if (f1 > f2) return 1;
  if (f1 < f2) return -1;
  return 0;
}

int main(int argc, char **argv){
  size_t SIZE = 15;
  char b[SIZE];
  char *token;
  FILE *f;
  double fl;
  double arr[100];
  double *tmp;
  size_t size ;

  //arr = NULL;
  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    token = strtok(b, " ");
    size = 0;
    while (token != NULL){
      printf("token: %s\n", token);
      size++;
      //realloc fails on Mavericks 
      //tmp = malloc(sizeof(fl) * size);
      //for(int i=0; i<size - 1; i++){
      //	tmp[i] = arr[i];
      //}
      //free(arr);
      //arr = tmp;
      fl = atof(token);
      printf("fl: %f\n", fl);
      arr[size - 1] = fl;
      token = strtok(NULL, " ");   
    }
    printf("found %lu floats:", size);
    qsort(arr, size, sizeof(fl), comp);
    for(int i=0; i<size; i++){
      printf("%f ", arr[i]);
    }
    printf("\n");
    //free(arr);
  }    
  fclose(f);
}
