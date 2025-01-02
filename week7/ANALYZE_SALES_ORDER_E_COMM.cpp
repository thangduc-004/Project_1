#include <bits/stdc++.h>

using namespace std;

string customer_id;
string product_id;
int price;
string shop_id;
string time_point;
int total_number_order = 0;
int total_revenue = 0;
map <string, int> revenue_of_shop;
map <pair <string, string>, int> total_consume_of_customer_shop;
vector <int> revenue_in_period(86400, 0);
int t;

/*bool check()
{
    t = 0;
    int cus = customer_id.length();
    int pro = product_id.length();
    int sho = shop_id.length();
    string h = time_point.substr(0, 2);
    string m = time_point.substr(3, 4);
    string s = time_point.substr(6, 7);
    int hi = stoi(h);
    int mi = stoi(m);
    int si = stoi(s);
    if (cus < 3 || cus > 10) return false;
    if (pro < 3 || pro > 10) return false;
    if (sho < 3 || sho > 10) return false;
    if (price < 1 || price > 1000) return false;
    if (hi < 0 || hi > 23 || mi < 0 || mi > 59 || si < 0 || si > 59)
        return false;
    t = hi * 3600 + mi * 60 + si;
    return true;
}*/

int count_time(string time_point)
{
    string h = time_point.substr(0, 2);
    string m = time_point.substr(3, 2);
    string s = time_point.substr(6, 2);
    int hi = stoi(h);
    int mi = stoi(m);
    int si = stoi(s);
    return hi * 3600 + mi * 60 + si;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> customer_id;
    while (customer_id != "#")
    {
        cin >> product_id >> price >> shop_id >> time_point;
        //if (check())
        //{
            total_number_order++;
            total_revenue += price;
            revenue_of_shop[shop_id] += price;
            total_consume_of_customer_shop[{customer_id, shop_id}] += price;
            t = count_time(time_point);
            revenue_in_period[t] += price;
        //}
        cin >> customer_id;
    }
    // Prefix Sum
    for (int i = 1; i < 86400; ++i) {
        revenue_in_period[i] += revenue_in_period[i - 1];
    }
    string queires;
    cin >> queires;
    while (queires != "#")
    {
        if (queires == "?total_number_orders")
            cout << total_number_order << endl;
        else if (queires == "?total_revenue")
            cout << total_revenue << endl;
        else if (queires == "?revenue_of_shop")
        {
            string shop1;
            cin >> shop1;
            cout << revenue_of_shop[shop1] << endl;
        }
        else if (queires == "?total_consume_of_customer_shop")
        {
            string customer;
            string shop;
            cin >> customer >> shop;
            cout << total_consume_of_customer_shop[{customer, shop}] << endl;
        }
        else if (queires == "?total_revenue_in_period")
        {
            int total_revenue_in_period;
            string from_time;
            string to_time;
            cin >> from_time >> to_time;
            int from = count_time(from_time);
            int to = count_time(to_time);
            total_revenue_in_period = revenue_in_period[to] - revenue_in_period[from - 1];
            cout << total_revenue_in_period << endl;
        }
        cin >> queires;
    }
    return 0;
}
