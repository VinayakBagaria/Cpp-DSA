// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time, i, j
    typedef pair<int, pair<int, int>> PP;

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        while (!pq.empty()) {
            auto [time, tp] = pq.top();
            auto [i, j] = tp;
            pq.pop();

            if (i == n-1 && j == m-1) return time;

            for (auto& it : directions) {
                int ni = i + it[0];
                int nj = j + it[1];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                int nextTime = max(time, moveTime[ni][nj]) + 1;

                if (nextTime < minTime[ni][nj]) {
                    minTime[ni][nj] = nextTime;
                    pq.push({nextTime, {ni, nj}});
                }
            }
        }

        return -1;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0, 4}, {4, 4}};
    cout << sol.minTimeToReach(vec) << endl;
    vec = {{0, 0, 0}, {0, 0, 0}};
    cout << sol.minTimeToReach(vec) << endl;
    vec = {{0, 1}, {1, 2}};
    cout << sol.minTimeToReach(vec) << endl;
}
