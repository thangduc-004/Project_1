#include <bits/stdc++.h>

using namespace std;

string from_account;
string to_account;
int money;
string time_point;
string atm;
int h, m, s;
int number_transactions = 0;
int total_money_transaction = 0;
set <string> list_sort_acc;
map <string, int> total_money_from;
map <string, vector<string>> adj;

string queries;

bool check()
{
    if (from_account.length() < 6 || from_account.length() > 20) return false;
    if (to_account.length() < 6 || to_account.length() > 20) return false;
    //if (money < 1 || money > 10000) return false;
    string hs = time_point.substr(0,1);
    string ms = time_point.substr(3,4);
    string ss = time_point.substr(6,7);
    h = stoi(hs);
    m = stoi(ms);
    s = stoi(ss);
    if (h > 23 || m > 60 || s > 60 || h < 0 || m < 0 || s < 0)
        return false;
    if (atm.length() < 3 || atm.length() > 10) return false;
    return true;
}

bool inspect_cycle(string acc1, string acc2, int target, set <string> &visited)
{
    if (target == 0)
    {
        if (acc1 == acc2)
        return true;
        else return false;
    }
    if (visited.count(acc2)) return false;
    visited.insert(acc2);

    for (const string& next : adj[acc2]) {
        if (inspect_cycle(acc1, next, target - 1, visited)) {
            return true;
        }
    }

    visited.erase(acc2);
    return false;
}

int main()
{
    cin >> from_account;
    while (from_account != "#")
    {
        cin >> to_account >> money >> time_point >> atm;
        if (check())
        {
            number_transactions++;
            total_money_transaction += money;
            list_sort_acc.insert(from_account);
            list_sort_acc.insert(to_account);
            total_money_from[from_account] += money;
            adj[from_account].push_back(to_account);
            //visited[from_account] = false;
        }
        cin >> from_account;
    }
    cin >> queries;
    while (queries != "#")
    {
        if (queries == "?number_transactions")
            cout << number_transactions << endl;
        else if (queries == "?total_money_transaction")
            cout << total_money_transaction << endl;
        else if (queries == "?list_sorted_accounts")
        {
            for (auto i : list_sort_acc)
                cout << i << " ";
            cout << endl;
        }
        else if (queries == "?total_money_transaction_from")
        {
            string account;
            cin >> account;
            cout << total_money_from[account] << endl;
        }
        else if (queries == "?inspect_cycle")
        {
            string acc;
            int target;
            cin >> acc >> target;
            //reset();
            set <string> visited;
            if (inspect_cycle(acc, acc, target, visited))
                cout << 1 << endl;
            else cout << 0 << endl;
        }
        cin >> queries;
    }
    return 0;
}
