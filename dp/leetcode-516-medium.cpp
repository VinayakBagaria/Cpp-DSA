// https://leetcode.com/problems/longest-palindromic-subsequence/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(int l, int r, string& s, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) return dp[l][r];

        int result;
        if (s[l] == s[r]) {
            int count = l == r ? 1 : 2;
            result = count + solve(l + 1, r - 1, s, dp);
        } else {
            result = solve(l + 1, r, s, dp);
            result = max(result, solve(l, r - 1, s, dp));
        }

        return dp[l][r] = result;
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(l, r, s, dp);
    }

    int bottomUp(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                if (s[l - 1] == rev[r - 1]) {
                    dp[l][r] = 1 + dp[l - 1][r - 1];
                } else {
                    dp[l][r] = max(dp[l - 1][r], dp[l][r - 1]);
                }
            }
        }

        return dp[n][n];
    }

    int bottomUpLinear(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                if (s[l - 1] == rev[r - 1]) {
                    curr[r] = 1 + prev[r - 1];
                } else {
                    curr[r] = max(prev[r], curr[r - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};

void doWork() {
    Solution sol;
    cout << sol.longestPalindromeSubseq("bbbab") << endl;
    cout << sol.bottomUpLinear("bbbab") << endl;
    cout << sol.longestPalindromeSubseq("cbbd") << endl;
    cout << sol.bottomUpLinear("cbbd") << endl;
    cout << sol.longestPalindromeSubseq("aaa") << endl;
    cout << sol.bottomUpLinear("aaa") << endl;
    cout << sol.longestPalindromeSubseq("a") << endl;
    cout << sol.bottomUpLinear("a") << endl;
}
