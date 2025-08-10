// https://leetcode.com/problems/detonate-the-maximum-bombs/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        int count = 1;

        for (int v : adj[src]) {
            if (!vis[v]) {
                count += dfs(v, adj, vis);
            }
        }

        return count;
    }

    bool isInRange(vector<int>& b1, vector<int>& b2) {
        long long dx = 1LL * (b2[0] - b1[0]);
        long long dy = 1LL * (b2[1] - b1[1]);
        long long r = 1LL * b1[2] * b1[2];

        return (dx * dx) + (dy * dy) <= r;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isInRange(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n);
            if (!vis[i]) {
                count = max(count, dfs(i, adj, vis));
            }
        }
        return count;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2,1,3}, {6,1,4}};
    cout << sol.maximumDetonation(vec) << endl;
    vec = {{1,1,5}, {10,10, 5}};
    cout << sol.maximumDetonation(vec) << endl;
    vec = {{1,2,3}, {2,3,1}, {3,4,2}, {4,5,3}, {5,6,4}};
    cout << sol.maximumDetonation(vec) << endl;
}

