#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>> a;

int descendants(string s3){
    int sum = 0;
    for(auto child : a[s3]){
        if(a.count(s3) == 1){
            sum += 1 + descendants(child);
        }
        else sum += 1;
    }
    return sum;
}

int generation(string s3){
    int sum = 0;
    if(a.count(s3) == 0) return 0;
 
    for(auto child : a[s3]){
        int i = 1 + generation(child);
        sum = max(sum,i);
    }
    return sum;
}

int main(){
    string input,input2,s1,s2;

    while(getline(cin, input)){
        if(input == "***") break;
        stringstream ss(input);
        ss >> s1 >> s2;
        a[s2].push_back(s1);
    }
    while(cin >> input2){
        if(input2 == "***") break;
        if(input2 == "descendants"){
            string s3; cin >> s3;
            cout << descendants(s3) << endl;
        }
        if(input2 == "generation"){
            string s3; cin >> s3;
            cout << generation(s3) << endl;
        }
    }
    return 0;
}
