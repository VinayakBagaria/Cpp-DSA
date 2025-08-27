// https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    pair<bool, vector<int>> getTeam(vector<vector<int>> &adj, int n) {
        vector<int> visited(n + 1);
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
            }

            int assigned = visited[i];
            int rev = assigned == 1 ? 2 : 1;

            for (auto& it : adj[i]) {
                if (visited[it] == assigned) {
                    return {false, vector<int>{}};
                }

                if (visited[it] == 0) {
                    visited[it] = rev;
                }
            }
        }

        return {true, visited};
    }
};

void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol = Solution();
    auto [possible, visited] = sol.getTeam(adj, n);
    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 1; i < visited.size(); i++) cout << visited[i] << " ";
    
    cout << endl;
}
