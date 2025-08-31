// https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u, int parentColor, vector<vector<int>>& adj, vector<int>& colors) {
        colors[u] = parentColor;
        
        for (int& it : adj[u]) {
            if (colors[it] == -1) {
                if (dfs(it, !parentColor, adj, colors) == false) {
                    return false;
                }
            } else if (colors[it] == parentColor) {
                return false;
            }
        }

        return true;
    }

    pair<bool, vector<int>> getTeam(vector<vector<int>> &adj, int n) {
        vector<int> colors(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (colors[i] == -1 && dfs(i, 0, adj, colors) == false) {
                return {false, colors};
            }
        }

        return {true, colors};
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
    auto [possible, colors] = sol.getTeam(adj, n);
    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) cout << colors[i] + 1 << " ";
}
