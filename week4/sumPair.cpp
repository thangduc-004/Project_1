//c++

#include <stdio.h>
#include <unordered_set>

int main() {
    int n, M;
    scanf("%d %d", &n, &M);  

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    }

    std::unordered_set<int> seen; 
    int count = 0;                 

    for (int i = 0; i < n; i++) {
        int complement = M - a[i];  
        if (seen.find(complement) != seen.end()) {
            count++; 
        }
        seen.insert(a[i]);  
    }

    printf("%d\n", count); 

    return 0;
}
