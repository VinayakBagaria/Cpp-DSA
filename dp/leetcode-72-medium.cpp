// https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void print(vector<vector<int>> result) {
        for (auto row : result) {
            for (auto e : row) {
                cout << e << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (i == word1.size()) {
            return word2.size() - j;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int result = 1e9;
        // Replace word1[i] with word2[j]
        if (word1[i] == word2[j]) {
            result = min(result, solve(i + 1, j + 1, word1, word2, dp));
        } else {
            result = min(result, 1 + solve(i + 1, j + 1, word1, word2, dp));
        }

        // Remove word1[i]
        result = min(result, 1 + solve(i + 1, j, word1, word2, dp));

        // Insert word1[i]
        result = min(result, 1 + solve(i, j + 1, word1, word2, dp));

        return dp[i][j] = result;
    }

public:
    int bottomUp(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();
        vector<vector<int>> dp(w1 + 1, vector<int>(w2 + 1, 0));
        for (int i = 0; i <= w1; i++) dp[i][0] = i;
        for (int j = 0; j <= w2; j++) dp[0][j] = j;

        for (int i = 1; i <= w1; i++) {
            for (int j = 1; j <= w2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
                }
            }
        }

        return dp[w1][w2];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2, dp);
    }
};


void doWork() {
    Solution sol;
    cout << sol.minDistance("horse", "ros") << endl;
    cout << sol.bottomUp("horse", "ros") << endl;

    cout << sol.minDistance("intention", "execution") << endl;
    cout << sol.bottomUp("intention", "execution") << endl;

    cout << sol.minDistance("", "a") << endl;
    cout << sol.bottomUp("", "a") << endl;
}
