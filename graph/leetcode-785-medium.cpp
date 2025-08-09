// https://leetcode.com/problems/is-graph-bipartite/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& colors) {
        for (int v : adj[u]) {
            if (colors[v] != -1) {
                if (colors[v] == colors[u]) {
                    return false;
                }
            } else {
                colors[v] = colors[u] == 0 ? 1 : 0;
                if (!dfs(v, adj, colors)) {
                    return false;
                }
            }

        }

        return true;
    }


    bool bfs(int src, vector<vector<int>>& adj, vector<int>& colors) {
        queue<int> q;
        colors[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (colors[v] == -1) {
                    colors[v] = !colors[u];
                    q.push(v);
                } else if (colors[u] == colors[v]) {
                    return false;
                }
            }
        }

        return true;
    }
    
    
    bool isBipartiteBfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!bfs(i, graph, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartiteDfs(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, graph, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        return isBipartiteBfs(graph);
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << sol.isBipartite(vec) << endl;
    vec = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << sol.isBipartite(vec) << endl;
}