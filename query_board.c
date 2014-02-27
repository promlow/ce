#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE  256

static const char* sc =  "SetCol";
static const char* sr = "SetRow";
static const char* qc = "QueryCol";
static const char* qr = "QueryRow";

int query_col(int** board, int col){
  int sum = 0;
  int i;
  for(i=0; i<SIZE; i++){
    sum += board[i][col];
  }
  return sum;
}

int query_row(int** board, int row){
  int sum = 0;
  int i;
  for(i=0; i<SIZE; i++){
    sum += board[row][i];
  }
  return sum;
}

void set_row(int **board, int row, int val){
  int i;
  for(i=0; i<SIZE; i++){
    board[row][i] = val;
  }
}

void set_col(int **board, int col, int val){
  int i;
  for(i=0; i<SIZE; i++){
    board[i][col] = val;
  }
}

int main(int argc, char **argv){
  char b[SIZE];
  int **board;
  FILE *f;

  board = calloc(sizeof(int*), SIZE );
  if(board == NULL){
    printf("Failed initial malloc\n");
    exit(-1);
  }

  int i;
  for(i=0; i<SIZE; i++){
    board[i] = calloc(sizeof(int), SIZE );
    if(board[i] == NULL){
      printf("Failed %d malloc\n", i);
    }
  }

  f = fopen(argv[1], "r");
  while ( (fgets(b, SIZE , f) != NULL) ){
    char *comm = strtok(b, " ");
    int roc = 0;
    int val = 0;
    if( (strspn(comm, sc) == strlen(sc))){
      roc = atoi(strtok(NULL, " "));
      val = atoi(strtok(NULL, " "));
      set_col(board, roc, val);
    }else if( (strspn(comm, sr)) == strlen(sr) ){
      roc = atoi(strtok(NULL, " "));
      val = atoi(strtok(NULL, " "));
      set_row(board, roc, val);
    }else if( (strspn(comm, qc)) == strlen(qc) ){
      roc = atoi(strtok(NULL, " "));
      printf("%d\n", query_col(board, roc));
    }else if( (strspn(comm, qr)) == strlen(qr) ){
      roc = atoi(strtok(NULL, " "));
      printf("%d\n", query_row(board, roc));
    }

  }

  for(i=0; i<SIZE; i++){
    free( board[i] );
  }

  free(board);
  fclose(f);
  exit(0);
}
