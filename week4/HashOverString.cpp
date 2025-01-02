//C++

#include <bits/stdc++.h>
using namespace std;
int n,m;
int power(int a,int k){
    int result = 1;
    while(k > 0){
        if(k % 2 == 1){
            result = (result*a)%m;
        }
        k = k/2;
        a = (a*a)%m;
    }
    return result;
}
int maBam(string s){
    int k = s.size();
    int result = 0;
    for(int i = 1; i <= k; i++){
        result += (int(s[i-1])*power(256,k-i))%m;
    }
    return result%m;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        cout << maBam(s) << endl;
    }
    return 0;
}
