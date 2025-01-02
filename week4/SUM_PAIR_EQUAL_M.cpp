//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int n, M;
int a[MAX];
int sum = 0;
int count_M = 0;

int main()
{
    cin >> n >> M;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int s = 0, e = n - 1;
    while (s < e)
    {
        if (a[s] + a[e] < M) s++;
        else if (a[s] + a[e] > M) e--;
        else
        {
            count_M++;
            s++;
            e--;
        }
    }
    cout << count_M;
    return 0;
}
