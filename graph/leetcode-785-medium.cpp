// https://leetcode.com/problems/is-graph-bipartite/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& colors) {
        for (int v : adj[u]) {
            if (colors[v] != -1) {
                if (colors[v] == colors[u]) {
                    return false;
                }
            } else {
                colors[v] = colors[u] == 0 ? 1 : 0;
                if (!dfs(v, adj, colors)) {
                    return false;
                }
            }

        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        vector<vector<int>> adj(n);
        for (int u = 0; u < graph.size(); u++) {
            for (int v : graph[u]) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (!dfs(i, adj, colors)) {
                    return false;
                }
            }
        }

        return true;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << sol.isBipartite(vec) << endl;
    vec = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << sol.isBipartite(vec) << endl;
}