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
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << sol.minFallingPathSum(vec) << endl;
    vec = {{-19, 57}, {-40, -5}};
    cout << sol.minFallingPathSum(vec) << endl;
}