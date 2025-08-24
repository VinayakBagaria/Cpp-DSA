// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time, u
    typedef pair<long long, int> PP;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, 0});
        vector<long long> minTime(n, LLONG_MAX);
        minTime[0] = 0;
        vector<int> pathCount(n, 0);
        pathCount[0] = 1;
        
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            for (auto& [v, duration] : adj[u]) {
                long long nextTime = time + duration;

                if (nextTime < minTime[v]) {
                    minTime[v] = nextTime;
                    if (u != n-1) {
                        pq.push({nextTime, v});
                    }
                    pathCount[v] = pathCount[u];
                } else if (nextTime == minTime[v]) {
                    minTime[v] = nextTime;
                    pathCount[v] += pathCount[u];
                    pathCount[v] %= MOD;
                }
            }
        }

        return pathCount[n-1];
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0,6,7}, {0,1,2}, {1,2,3}, {1,3,3}, {6,3,3}, {3,5,1}, {6,5,1}, {2,5,1}, {0,4,5}, {4,6,2}};
    cout << sol.countPaths(7, vec) << endl;
    vec = {{1, 0, 10}};
    cout << sol.countPaths(2, vec) << endl;
}
