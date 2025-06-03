// https://www.geeksforgeeks.org/problems/bipartite-graph/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    unordered_map<int, vector<int>> makeAdj(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edg : edges) {
            int u = edg[0], v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return adj;
    }
    
    bool dfs(int node, int currColor, unordered_map<int, vector<int>>& adj, vector<int>& color) {
        color[node] = currColor;
        
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !currColor, adj, color) == false) {
                    return false;
                }
            } else if (color[it] == currColor) {
                return false;
            }
        }
        
        return true;
    }

  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj = makeAdj(edges);
        
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1 && dfs(i, 0, adj, color) == false) {
                return false;
            }
        }
        
        return true;
    }
};

void doWork() {
    Solution sol = Solution();
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << sol.isBipartite(3, edges) << endl;


    edges = {{0, 3}, {1, 2}, {3, 2}, {0, 2}};
    cout << sol.isBipartite(4, edges) << endl;
}