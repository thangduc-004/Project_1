//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int t;
int n, m;
int bac[MAX];

int main()
{
    cin >> t;
    while (t--)
    {
        int check = 1;
        cin >> n >> m;
        fill_n(bac, n + 1, 0);
        if (n <= 2)
        {
            cout << 1;
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            bac[a]++;
            bac[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (bac[i] < n/2)
            {
                check = 0;
                break;
            }
        }
        cout << check << endl;
    }
    return 0;
}

