// https://cses.fi/problemset/task/1667/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    pair<vector<int>, vector<int>> getRoute(vector<vector<int>> &adj, int n) {
        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        vector<int> dist(n + 1, INT_MAX), parent(n + 1);
        dist[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        return {dist, parent};
    }
};

void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol = Solution();
    auto [dist, parent] = sol.getRoute(adj, n);
    if (dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << dist[n] + 1 << endl;

    vector<int> route;
    int node = n;

    while (n != 1) {
        route.push_back(n);
        n = parent[n];
    }
    route.push_back(1);
    reverse(route.begin(), route.end());

    for (auto& it : route) cout << it << " ";
    
    cout << endl;
}
