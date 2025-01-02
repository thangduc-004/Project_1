#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int n, m;
vector <int> adj[MAX];
bool visited[MAX];

void bfs(int root)
{
    queue <int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        sort(adj[u].begin(), adj[u].end());
        for (auto i: adj[u])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill_n(visited, n + 1, false);
    for (int i = 1; i < n; i++)
        if (!visited[i])
            bfs(i);
    return 0;
}
