// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheCity(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto edg : edges) {
            int u = edg[0], v = edg[1], wt = edg[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            dijkstra(i, dist[i], adj);
        }

        int adjCount = n;
        int city = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= adjCount) {
                adjCount = count;
                city = i;
            }
        }
        return city;
    }

    void dijkstra(int src, vector<int>& dist, unordered_map<int, vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            for (auto it : adj[curr]) {
                int v = it.first, cost = it.second;

                int newDist = wt + cost;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }
};


void doWork() {
    Solution sol = Solution();
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << sol.findTheCity(4, {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4) << endl;
}
