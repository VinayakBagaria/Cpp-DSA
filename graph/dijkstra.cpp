// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, const vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto edg : edges) {
            int u = edg[0], v = edg[1], wt = edg[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) {
                int neigh = it.first;
                int wt = it.second;

                int newDist = currDist + wt;
                if (newDist < dist[neigh]) {
                    dist[neigh] = newDist;
                    pq.push({newDist, neigh});
                }
            }
        }
        
        return dist;
    }
};

void doWork() {
    Solution sol = Solution();
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    auto ans = sol.dijkstra(3, {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}}, 2);

    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}