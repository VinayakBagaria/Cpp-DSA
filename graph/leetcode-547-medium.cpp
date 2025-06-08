// https://leetcode.com/problems/number-of-provinces/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};

void doWork() {
    Solution s;
    cout << s.findCircleNum({{1,1,0},{1,1,0},{0,0,1}}) << endl;
    cout << s.findCircleNum({{1,0,0},{0,1,0},{0,0,1}}) << endl;
}
