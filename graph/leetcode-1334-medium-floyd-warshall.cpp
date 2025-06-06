// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheCity(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto edg : edges) {
            int u = edg[0], v = edg[1], wt = edg[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
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
};

void doWork() {
    Solution sol = Solution();
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << sol.findTheCity(4, {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4) << endl;
}
