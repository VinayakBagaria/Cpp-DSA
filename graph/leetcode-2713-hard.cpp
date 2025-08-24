#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int m = grid.size(), n = grid[0].size();
        int maxi = 0;

        for (int r = 0; r < m; r++) {
            if (grid[i][j] < grid[r][j]) {
                maxi = max(maxi, dfs(grid, r, j, dp));
            }
        }

        for (int c = 0; c < n; c++) {
            if (grid[i][j] < grid[i][c]) {
                maxi = max(maxi, dfs(grid, i, c, dp));
            }
        }

        return dp[i][j] = 1 + maxi;
    }

    int maxIncreasingCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, dfs(grid, i, j, dp));
            }
        }

        return maxi;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{3, 1}, {3, 4}};
    cout << sol.maxIncreasingCells(vec) << endl;
    vec = {{1, 1}, {1, 1}};
    cout << sol.maxIncreasingCells(vec) << endl;
    vec = {{3, 1, 6}, {-9, 5, 7}};
    cout << sol.maxIncreasingCells(vec) << endl;
}
