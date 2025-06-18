// https://leetcode.com/problems/longest-common-subsequence/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(int i, int j, int n, int m, string& t1, string& t2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int result = 1e9;
        if (t1[i] == t2[j]) {
            result = 1 + solve(i - 1, j - 1, n, m, t1, t2, dp);
        } else {
            result = solve(i - 1, j, n, m, t1, t2, dp);
            result = max(result, solve(i, j - 1, n, m, t1, t2, dp));
        }

        return dp[i][j] = result;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, n, m, text1, text2, dp);
    }

    int bottomUp(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }

    int bottomUpLinear(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};

void doWork() {
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    cout << sol.bottomUp("abcde", "ace") << endl;
    cout << sol.bottomUpLinear("abcde", "ace") << endl;
    cout << sol.longestCommonSubsequence("abc", "abc") << endl;
    cout << sol.bottomUp("abc", "abc") << endl;
    cout << sol.bottomUpLinear("abc", "abc") << endl;
    cout << sol.longestCommonSubsequence("abc", "def") << endl;
    cout << sol.bottomUp("abc", "def") << endl;
    cout << sol.bottomUpLinear("abc", "def") << endl;
}
