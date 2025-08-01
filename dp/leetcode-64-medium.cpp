// https://leetcode.com/problems/minimum-path-sum/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 1e9;
        if (r == m-1 && c == n-1) return grid[r][c];

        if (dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = grid[r][c] + min(solve(r + 1, c, m, n, grid, dp), solve(r, c + 1, m, n, grid, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, grid, dp);
    }

    int bottomUp(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));

        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (r == m-1 && c == n-1) {
                    dp[r][c] = grid[r][c];
                } else {
                    dp[r][c] = grid[r][c];
                    int mini = 1e9;
                    if (r + 1 < m) mini = min(mini, dp[r+1][c]);
                    if (c + 1 < n) mini = min(mini, dp[r][c+1]);
                    dp[r][c] += mini == 1e9 ? 0 : mini;
                }
            }
        }

        return dp[0][0];
    }

    int spaceBottomUp(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 1e9), curr(n, 1e9);

        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (r == m-1 && c == n-1) {
                    curr[c] = grid[r][c];
                } else {
                    curr[c] = grid[r][c];
                    int mini = 1e9;
                    if (r + 1 < m) mini = min(mini, prev[c]);
                    if (c + 1 < n) mini = min(mini, curr[c+1]);
                    curr[c] += mini == 1e9 ? 0 : mini;
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << sol.minPathSum(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{1, 2, 3}, {4, 5, 6}};
    cout << sol.minPathSum(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
}