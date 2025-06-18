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
};

void doWork() {
    Solution sol;
    cout << sol.longestPalindromeSubseq("bbbab") << endl;
    // cout << sol.bottomUp("bbbab") << endl;
    cout << sol.longestPalindromeSubseq("cbbd") << endl;
    // cout << sol.bottomUp("cbbd") << endl;
    cout << sol.longestPalindromeSubseq("aaa") << endl;
    // cout << sol.bottomUp("aaa") << endl;
    cout << sol.longestPalindromeSubseq("a") << endl;
    // cout << sol.bottomUp("a") << endl;
}
