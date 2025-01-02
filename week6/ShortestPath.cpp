#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<pair<int, int>>> a;
vector<int> vt;

void dijkstra(int s, int n) {
    vt.assign(n + 1, MOD);
    vt[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > vt[u]) continue;

        for (auto x : a[u]) {
            int v = x.first;
            int w = x.second;

            if (vt[u] + w < vt[v]) {
                vt[v] = vt[u] + w;
                pq.push({vt[v], v});
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    a.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s, n);

    if (vt[t] == MOD) {
        cout << -1 << endl;
    } else {
        cout << vt[t] << endl;
    }

    return 0;
}
