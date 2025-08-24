// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    const int MOD = 1e9 + 7;

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int m = grid.size(), n = grid[0].size();
        int count = 1;

        for (auto& [dx, dy] : directions) {
            int ni = i + dx, nj = j + dy;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[i][j] >= grid[ni][nj]) {
                continue;
            }

            count = (count + dfs(grid, ni, nj, dp)) % MOD;
        }

        return dp[i][j] = count;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count = (count + dfs(grid, i, j, dp)) % MOD;
            }
        }

        return count;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 1}, {3, 4}};
    cout << sol.countPaths(vec) << endl;
}
