//C++ 
#include <bits/stdc++.h> 
using namespace std;

int total_orders = 0;
int total_revenue = 0;
map<string,int> shop;
map<string,map<string,int>> kh;
vector<int> vt(86400,0);

int to_s(const string &s){
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
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
        string customerID, productID, shopID, timePoint;
        int price;
        stringstream ss(input);
        ss >> customerID >> productID >> price >> shopID >> timePoint;
        total_orders++;
        total_revenue += price;
        shop[shopID] += price;
        kh[customerID][shopID] += price;
        int time = to_s(timePoint);
        vt[time] += price;
    }

    int S[86400];
    S[0] = vt[0];
    for(int i = 1; i < 86400; i++){
        S[i] = S[i-1] + vt[i];
    }

    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "?total_number_orders") cout << total_orders << endl;
        else if(s == "?total_revenue") cout << total_revenue << endl;
        else if(s == "?revenue_of_shop"){
            string tmp; cin >> tmp;
            cout << shop[tmp] << endl;
        }
        else if(s == "?total_consume_of_customer_shop"){
            string tmp1, tmp2; cin >> tmp1 >> tmp2;
            cout << kh[tmp1][tmp2] << endl;
        }
        else if(s == "?total_revenue_in_period"){
            string time1, time2; cin >> time1 >> time2;
            int tmp1 = to_s(time1), tmp2 = to_s(time2);
            int res = S[tmp2] - S[tmp1-1];
            cout << res << endl;
        }
    }
    return 0;
}