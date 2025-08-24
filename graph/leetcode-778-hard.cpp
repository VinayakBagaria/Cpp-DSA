// https://leetcode.com/problems/swim-in-rising-water/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // time, i, j
    typedef tuple<int, int, int> PP;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        minTime[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n-1 && y == n-1) return time;

            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                int nextTime = max(time, grid[nx][ny]);
                if (nextTime < minTime[nx][ny]) {
                    minTime[nx][ny] = nextTime;
                    pq.push({nextTime, nx, ny});
                }
            }
        }

        return -1;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0, 2}, {1, 3}};
    cout << sol.swimInWater(vec) << endl;
    vec = {{0, 1, 2, 3, 4}, {24,23,22,21,5}, {12,13,14,15,16}, {11,17,18,19,20}, {10,9,8,7,6}};
    cout << sol.swimInWater(vec) << endl;
    vec = {{3, 2}, {0, 1}};
    cout << sol.swimInWater(vec) << endl;
}
