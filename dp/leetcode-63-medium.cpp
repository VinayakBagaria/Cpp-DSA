// https://leetcode.com/problems/unique-paths-ii/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (grid[r][c] == 1) return 0;
        if (r == m-1 && c == n-1) return 1;

        if (dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = solve(r + 1, c, m, n, grid, dp) + solve(r, c + 1, m, n, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, grid, dp);
    }

    int bottomUp(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[m-1][n-1] = 1;

        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (grid[r][c] != 0) continue;

                if (r + 1 < m) dp[r][c] += dp[r + 1][c];
                if (c + 1 < n) dp[r][c] += dp[r][c + 1];
            }
        }

        return (int)dp[0][0];
    }

    int spaceBottomUp(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;

        vector<long long> prev(n, 0), curr(n, 0);

        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    curr[c] = 0;
                } else if (r == m - 1 && c == n - 1) {
                    curr[c] = 1;
                } else {
                    curr[c] = 0;
                    if (r + 1 < m) curr[c] += prev[c];
                    if (c + 1 < n) curr[c] += curr[c + 1];
                }

            }
            prev = curr;
        }

        return (int)prev[0];
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePathsWithObstacles(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{0, 1}, {0, 0}};
    cout << sol.uniquePathsWithObstacles(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{0, 0}, {0, 1}};
    cout << sol.uniquePathsWithObstacles(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{0, 1, 0, 0}};
    cout << sol.uniquePathsWithObstacles(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
}