#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int n, m;
int s, e;
vector <int> adj[10005];
map <pii, int> cap;
map <pii, int> f; // gia tri luong
int max_flow = 0;
int max_add;

bool bfs(int start, int e)
{
    queue<int> q;
    int dist[10005];
    int pre[10005];
    bool visited[10005];
    int max_add = INT_MAX;

    memset(visited, false, sizeof(visited));
    fill(dist, dist + n + 1, INT_MAX);
    memset(pre, -1, sizeof(pre));


    q.push(start);
    dist[start] = 0;
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();


        for (int v : adj[u])
        {
            if (!visited[v] && cap[{u, v}] > 0)
            {
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
                pre[v] = u;

                if (v == e) break;
            }
        }
    }

    if (!visited[e]) return false;

    int u = e;
    while (pre[u] != -1)
    {
        int v = pre[u];
        max_add = min(max_add, cap[{v, u}]);
        u = v;
    }

    u = e;
    while (pre[u] != -1)
    {
        int v = pre[u];
        cap[{v, u}] -= max_add;
        f[{v, u}] += max_add;
        u = v;
    }
    max_flow += max_add;
    return true;
}

void sol()
{
    while (bfs(s, e));
}

int main()
{
    cin >> n >> m;
    cin >> s >> e;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        cap[{a, b}] = c;
        f[{a, b}] = 0;
    }
    sol();
    cout << max_flow;
    return 0;
}
