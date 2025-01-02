#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int n, m;
set <pair<int, pair<int,int>>> s;
int ans = 0;
int edge = 0;
int father[MAX]; // Dung cho Union Set
int h[MAX]; // ..................

void makeset(int x)
{
    father[x] = x;
    h[x] = 0;
}

int find(int x)
{
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}

void unionset(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if (fx == fy) return;
    if (h[fx] > h[fy]) father[fy] = fx;
    else
        father[fx] = fy;
        if (h[fx] = h[fy]) h[fy] = h[fx] + 1;
}

int kruskal()
{
    for (auto i: s)
    {
        if (find(i.second.first) != find(i.second.second))
            {
                unionset(i.second.first, i.second.second);
                ans += i.first;
                if (++edge == n - 1) return ans;
            }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        s.insert({c, {a, b}});
    }
    for (int i = 1; i <= n; i++)
        makeset(i);
    cout << kruskal();
    return 0;
}


