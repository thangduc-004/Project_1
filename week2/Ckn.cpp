//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000007

long long c[501][1000], k, n;



int main()
{
    cin >> k >> n;
    for (int j = 1; j <= n; j++) c[1][j] = j;

    for (int i = 2; i <= k; i++)
    for (int j = i; j <= n; j++)
    {
        if (i == j) c[i][j] = 1;
        else
        {
            c[i][j] = (c[i - 1][j - 1] + c[i][j - 1]) % MAX;
        }
    }
    cout << c[k][n];
    return 0;
}
