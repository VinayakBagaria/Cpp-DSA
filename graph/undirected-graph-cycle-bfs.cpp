// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool bfs(int src, unordered_map<int, vector<int>>& adj, unordered_set<int>& childNodes) {
        // node, prev parent
        queue<pair<int, int>> q;
        q.push({src, -1});
        childNodes.insert(src);

        while (!q.empty()) {
            int u = q.front().first, parent = q.front().second;
            q.pop();

            for (int neigh : adj[u]) {
                if (childNodes.find(neigh) == childNodes.end()) {
                    q.push({neigh, u});
                    childNodes.insert(neigh);
                } else if (parent != neigh) {
                    // This means the neighbour was already visited by someone in the past
                    // So why the current node is again trying to access this node
                    // Even if I am accessing, it cannot be my 1-level upper parent
                    return true;
                }
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
        unordered_set<int> childNodes;

        // The loop is only to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (childNodes.find(i) == childNodes.end()) {
                if (bfs(i, adj, childNodes)) return true;
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
