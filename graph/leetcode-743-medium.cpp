// https://leetcode.com/problems/network-delay-time/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PP;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v, time});
        }

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, k});
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            for (auto& [v, duration] : adj[u]) {
                int nextTime = time + duration;
                if (nextTime < minTime[v]) {
                    minTime[v] = nextTime;
                    pq.push({nextTime, v});
                }
            }
        }

        int maxi = *max_element(minTime.begin() + 1, minTime.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << sol.networkDelayTime(vec, 4, 2) << endl;
    vec = {{1, 2, 1}};
    cout << sol.networkDelayTime(vec, 2, 1) << endl;
    cout << sol.networkDelayTime(vec, 2, 2) << endl;
}
