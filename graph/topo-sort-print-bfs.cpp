// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void dfs(int u, vector<bool>& visited, vector<int>& topo, vector<vector<int>>& adj) {
        visited[u] = true;

        for (int neigh : adj[u]) {
            if (!visited[neigh]) {
                dfs(neigh, visited, topo, adj);
            }
        }

        topo.push_back(u);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> topo;

        vector<vector<int>> adj(V);
        for (vector<int> edg : edges) {
            int u = edg[0], v = edg[1];
            adj[u].push_back(v);
        }


        vector<bool> visited(V);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, topo, adj);
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};

void print(vector<int> vec) {
    for (int it : vec) cout << it << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    print(sol.topoSort(4, edges));
    edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};
    print(sol.topoSort(6, edges));
}
