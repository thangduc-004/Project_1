#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int n,m;
vector <vector<int>> adj; // Ke
vector <vector<int>> d; // Khoang cach giua 2 dinh

void sol(int s)
{
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist;
    vector<int> prev;
    dist.resize(n);
    prev.resize(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999;
        prev[i] = -1;
    }
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();
        if (d_u > dist[u]) continue;
        for (auto v : adj[u])
            if (dist[v] > dist[u] + d[u][v])
            {
                dist[v] = dist[u] + d[u][v];
                prev[v] = u;
                pq.push({dist[v], v});
            }
    }
    for (int i = 0; i < n; i++)
        if (dist[i] == 9999) cout << "-1 ";
        else cout << dist[i] << " ";
    cout << "\n";
    return;
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    d.assign(n, vector<int>(n, 9999));
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back(b);
        d[a][b] = c;
    }
    for (int i = 0; i < n; i++)
    {
        sol(i);
    }
    return 0;
}
