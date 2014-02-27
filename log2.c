#include <stdio.h>

int clog2(long long x){
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

  printf("%d\n", clog2(5));
  printf("%d\n", clog2(8));
  printf("%d\n", clog2(128));

}
