// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool dfs(int src, int parent, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(src);

        for (int neigh : adj[src]) {
            if (visited.find(neigh) == visited.end()) {
                if (dfs(neigh, src, adj, visited)) {
                    return true;
                }
            } else if (parent != neigh) {
                // This means the neighbour was already visited by someone in the past
                // So why the current node is again trying to access this node
                // Even if I am accessing, it can only be my 1-level upper parent
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edg : edges) {
            int u = edg[0], v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // child nodes which have been pushed to queue
        unordered_set<int> visited;

        // The loop is only to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (visited.find(i) == visited.end()) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }

        return false;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    cout << sol.isCycle(4, edges) << endl;
    edges = {{0, 1}, {1, 2}, {2, 3}};
    cout << sol.isCycle(4, edges) << endl;
}
