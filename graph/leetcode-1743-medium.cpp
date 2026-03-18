// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int u, unordered_set<int>& visited, unordered_map<int, vector<int>>& adj, vector<int>& result) {
        result.push_back(u);
        visited.insert(u);

        for (int v : adj[u]) {
            if (!visited.count(v)) {
                dfs(v, visited, adj, result);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>> adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto &p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int start;
        for (auto &[u, nodes] : adj) {
            if (nodes.size() == 1) {
                start = u;
                break;
            }
        }

        unordered_set<int> visited;
        vector<int> result;
        dfs(start, visited, adj, result);
        return result;
    }
};

void print(vector<int> result) {
    for (auto r : result) cout << r << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    print(sol.restoreArray({{2, 1}, {3, 4}, {3, 2}}));
    print(sol.restoreArray({{4, -2}, {1, 4}, {-3, 1}}));
}
