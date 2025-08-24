// https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(int u, int time, int totalQ, vector<bool>& vis, vector<vector<pair<int, int>>>& adj, vector<int>& values, int maxTime) {
        if (time > maxTime) {
            return 0;
        }

        int maxi = 0;
        if (u == 0) {
            maxi = totalQ;
        }

        for (auto& [v, duration] : adj[u]) {
            // Scene 1: If node is not visited, mark visited in the current DFS scenario
            // Add quality of the node as it was not visited before this
            // Backtrack & mark node unvisited after DFS is complete

            // Scene 2: If the node was visited before hand, we are just going over it once again
            // So, just do DFS but don't add quality
            if (!vis[v]) {
                vis[v] = true;
                maxi = max(maxi, dfs(v, time + duration, totalQ + values[v], vis, adj, values, maxTime));
                vis[v] = false;
            } else {
                maxi = max(maxi, dfs(v, time + duration, totalQ, vis, adj, values, maxTime));
            }
        }

        return maxi;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<bool> vis(n);
        return dfs(0, 0, values[0], vis, adj, values, maxTime);
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
    vector<int> values = {0, 32, 10, 43};
    cout << sol.maximalPathQuality(values, edges, 49) << endl;
    edges = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}};
    values = {5, 10, 15, 20};
    cout << sol.maximalPathQuality(values, edges, 30) << endl;
}
