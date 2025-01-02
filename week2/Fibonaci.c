//c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int findF(int n){
    int f0 = 0, f1 = 1, fn = 0;
  for(int i = 0; i < n -1; i++){
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
  }  
  return fn;
}

int main() {
    
    int n;
    scanf("%d", &n);
    printf("%d", findF(n-1));


    return 0;
}
