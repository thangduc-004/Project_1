//C 
#include <stdio.h> 

int main() 
{
    int n;
    scanf("%d", &n);
    int a[1000];
    int k = 0;
    for(int i = 100; i<=999; i++){
        if(i % n == 0){
            a[k] = i;
            k++;
        }
    }
    for(int i=0; i<k; i++){
        printf("%d ", a[i]);
    }

}
