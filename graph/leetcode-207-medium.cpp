// https://leetcode.com/problems/course-schedule/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, vector<int>> adj;

        for (auto preq : prerequisites) {
            int u = preq[1], v = preq[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int neigh : adj[u]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

        return count == numCourses;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> preq = {{1, 0}};
    cout << sol.canFinish(2, preq) << endl;
    preq = {{1, 0}, {0, 1}};
    cout << sol.canFinish(2, preq) << endl;
}
