//C++ 
#include <bits/stdc++.h> 
using namespace std;

int total_transactions = 0;
int total_money = 0;
set<string> st;
unordered_map<string,int> tk1;
unordered_map<string, vector<string>> mp;

bool dfs(const string& start, const string& curr, int depth, int k, unordered_set<string>& visited) {
    if (depth == k) {
        return curr == start;
    }
    visited.insert(curr);
    for (const string& x : mp[curr]) {
        if (x == start && depth + 1 == k) {
            return true;
        }
        if (visited.find(x) == visited.end()) {
            if (dfs(start, x, depth + 1, k, visited)) {
                return true;
            }
        }
    }
    visited.erase(curr);
    return false;
}

bool inspect_cycle(const string& account, int k) {
    unordered_set<string> visited;
    return dfs(account, account, 0, k, visited);
}

int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    while(1){
        string input;
        getline(cin, input);
        if(input == "#") break;
        string from_account, to_account, time_point, atm;
        int money;
        stringstream ss(input);
        ss >> from_account >> to_account >> money >> time_point >> atm;
        total_transactions++;
        total_money += money;

        mp[from_account].push_back(to_account);
        
        tk1[from_account] += money;
        st.insert(from_account);
        st.insert(to_account);
    }
    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "?number_transactions") cout << total_transactions << endl;
        else if(s == "?total_money_transaction") cout << total_money << endl;
        else if(s == "?list_sorted_accounts"){
            for(string x : st){
                cout << x << " ";
            }
            cout << endl;
        }
        else if(s == "?total_money_transaction_from"){
            string tmp; cin >> tmp;
            cout << tk1[tmp] << endl;
        }
        else if(s == "?inspect_cycle"){
            string tmp;
            int k;
            cin >> tmp >> k;
            cout << (inspect_cycle(tmp, k) ? 1 : 0) << endl;
        }
    }

    return 0;
}