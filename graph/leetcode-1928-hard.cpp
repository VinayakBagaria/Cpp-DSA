// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // {fees, node, time}
    typedef pair<int, pair<int, int>> PP;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        // u -> {v, time}
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({fees[0], {0, 0}});
        vector<int> minTime(n, INT_MAX);

        while (!pq.empty()) {
            auto [currFees, tp] = pq.top();
            auto [u, currTime] = tp;
            pq.pop();

            if (u == n-1) return currFees;

            for (auto& [v, duration] : adj[u]) {
                int newTime = currTime + duration;
                int newFees = currFees + fees[v];

                if (newTime < minTime[v] && newTime <= maxTime) {
                    minTime[v] = newTime;
                    pq.push({newFees, {v, newTime}});
                }
            }
        }

        return -1;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> fees = {5, 1, 2, 20, 20, 3};
    cout << sol.minCost(30, edges, fees) << endl;
}