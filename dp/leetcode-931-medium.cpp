// https://leetcode.com/problems/minimum-falling-path-sum/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (r < 0 || r >= m || c < 0 || c >= n) return 1e9;
        if (r == m-1) return matrix[r][c];

        if (dp[r][c] != -1e9) return dp[r][c];

        return dp[r][c] = matrix[r][c] + min(solve(r + 1, c - 1, m, n, matrix, dp), 
                                        min(solve(r + 1, c, m, n, matrix, dp), solve(r + 1, c + 1, m, n, matrix, dp)));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));
        int ans = 1e9;
        for (int c = 0; c < n; c++) ans = min(ans, solve(0, c, m, n, matrix, dp));
        return ans;
    }

    int bottomUp(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (r == m-1) {
                    dp[r][c] = matrix[r][c];
                } else {
                    int mini = dp[r+1][c];
                    if (c >= 1) {
                        mini = min(mini, dp[r+1][c-1]);
                    }
                    if (c + 1 < n) {
                        mini = min(mini, dp[r+1][c+1]);
                    }
                    dp[r][c] = matrix[r][c] + mini;
                }
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }

    int spaceBottomUp(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n), curr(n);
        
        for (int r = m-1; r >= 0; r--) {
            for (int c = n-1; c >= 0; c--) {
                if (r == m-1) {
                    curr[c] = matrix[r][c];
                } else {
                    int mini = prev[c];
                    if (c >= 1) {
                        mini = min(mini, prev[c-1]);
                    }
                    if (c + 1 < n) {
                        mini = min(mini, prev[c+1]);
                    }
                    curr[c] = matrix[r][c] + mini;
                }
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << sol.minFallingPathSum(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{-19, 57}, {-40, -5}};
    cout << sol.minFallingPathSum(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
}