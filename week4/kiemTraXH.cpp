//C++
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> s;
vector<int> vt;

void check(int tmp){
    if(s.empty()) cout << 0 << endl;
    else{
        if(s.find(tmp) != s.end()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    s.insert(tmp);
}
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        check(tmp);
    }
    return 0;
}
