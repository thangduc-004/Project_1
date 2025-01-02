#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int n, m;
int s, e;
vector<vector<pii>> adj;

void sol(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, INT_MAX);

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();

        if (d_u > dist[u]) continue;

        for (auto [v, weight] : adj[u])
        {
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[e - 1] == INT_MAX)
        cout << "-1 ";
    else
        cout << dist[e - 1] << " ";
}

int main()
{
    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
    }

    cin >> s >> e;
    sol(s - 1);

    return 0;
}
