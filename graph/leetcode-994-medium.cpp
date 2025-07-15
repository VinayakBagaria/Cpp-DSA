// https://leetcode.com/problems/rotting-oranges/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int goodCount = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) goodCount++;
            }
        }

        if (goodCount == 0) return 0;

        int time = -1;

        while (!q.empty()) {
            int size = q.size();

            for (int k = 0; k < size; k++) {
                int i = q.front().first, j = q.front().second;
                q.pop();

                for (auto d : dirs) {
                    int nI = i + d.first;
                    int nJ = j + d.second;

                    if (nI < 0 || nI >= n || nJ < 0 || nJ >= m) continue;

                    if (grid[nI][nJ] == 1) {
                        grid[nI][nJ] = 2;
                        goodCount--;
                        q.push({nI, nJ});
                    }
                }
            }

            time++;
        }

        return goodCount == 0 ? time : -1;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(vec) << endl;
    vec = {{2,1,1},{0,1,1},{1,0,1}};
    cout << sol.orangesRotting(vec) << endl;
    vec = {{2,1,1},{1,1,1},{0,1,2}};
    cout << sol.orangesRotting(vec) << endl;
}