// https://leetcode.com/problems/find-eventual-safe-states
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe(n);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            safe[curr] = 1;

            for (int it : adj[curr]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

void doWork() {
    Solution s;
    auto result = s.eventualSafeNodes({{1,2},{2,3},{5},{0},{5},{},{}});
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}
