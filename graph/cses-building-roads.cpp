// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for (auto& it : adj[u]) {
            if (!visited[it]) {
                dfs(adj, it, visited);
            }
        }
    }

    vector<int> getRoads(vector<vector<int>> &adj, int n) {
        vector<bool> visited(n + 1);

        vector<int> bridges;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bridges.push_back(i);
                dfs(adj, i, visited);
            }
        }

        return bridges;
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
    vector<int> bridges = sol.getRoads(adj, n);
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
        cout << bridges[i] << " " << bridges[i+1] << endl;
    }
}
