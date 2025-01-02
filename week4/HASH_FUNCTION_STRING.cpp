//C++
#include <bits/stdc++.h>

using namespace std;

int n,m;
string s;

int solve(string s)
{
    int ans = 0;
    long long mu = 1;
    int len = s.length();
    for (int i = len - 1; i >= 0; i--)
    {
        ans += ((int)s[i] * mu) % m;
        mu = (mu * 256) % m;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    while(n--)
    {
        cin >> s;
        cout << solve(s) % m << endl;
    }
    return 0;
}
