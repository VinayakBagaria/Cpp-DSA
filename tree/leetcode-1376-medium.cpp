// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, const vector<int>& manager, const vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});

        int time = 0;
        while (!q.empty()) {
            int curr = q.front().first;
            int supTime = q.front().second;
            q.pop();

            time = max(time, supTime);

            for (auto it : adj[curr]) {
                q.push({it, supTime + informTime[it]});
            }
        }

        return time;
    }
};

void doWork() {
    Solution sol = Solution();
    cout << sol.numOfMinutes(1, 0, {-1}, {0}) << endl;
    cout << sol.numOfMinutes(6, 2, {2,2,-1,2,2,2}, {0,0,1,0,0,0}) << endl;
    cout << sol.numOfMinutes(7, 6, {1,2,3,4,5,6,-1}, {0,6,5,4,3,2,1}) << endl;
}