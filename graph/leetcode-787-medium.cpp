// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // cost, node
    typedef tuple<int, int> PP;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // u -> {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }

        queue<PP> q;
        q.push({0, src});
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [cost, u] = q.front();
                q.pop();

                for (auto& [v, w] : adj[u]) {
                    int nextCost = cost + w;
                    if (nextCost < minCost[v]) {
                        minCost[v] = min(minCost[v], nextCost);
                        q.push({nextCost, v});
                    }
                }
            }

            stops++;
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};


void doWork() {
    Solution sol;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << sol.findCheapestPrice(4, flights, 0, 3, 1) << endl;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1) << endl;
    flights = {{0, 1, 5}, {1, 2, 5}, {0, 3, 2}, {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
    cout << sol.findCheapestPrice(5, flights, 0, 2, 2) << endl;
}
