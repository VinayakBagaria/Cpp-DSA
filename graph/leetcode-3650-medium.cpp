// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // cost, node
    typedef tuple<int, int> PP;

    int minCost(int n, vector<vector<int>>& edges) {
        // u -> {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, 0});
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;

        while(!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (u == n-1) return cost;

            for (auto& [v, w] : adj[u]) {
                int nextCost = cost + w;

                if (nextCost < minCost[v]) {
                    minCost[v] = nextCost;
                    pq.push({nextCost, v});
                }
            }
        }

        return -1;
    }
};


void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    cout << sol.minCost(4, vec) << endl;
}
