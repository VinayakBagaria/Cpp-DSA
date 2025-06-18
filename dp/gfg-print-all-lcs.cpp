// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, unordered_set<string>> memo;

private:
    void print(vector<string> result) {
        for (auto r : result) cout << r << " ";
        cout << endl;
    }

    vector<vector<int>> bottomUp(string& t1, string& t2) {
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

        return dp;
    }

public:
    unordered_set<string> findLcsSeq(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        unordered_set<string> st;

        if (i == 0 || j == 0) {
            st.insert("");
            return st;
        };

        string key = to_string(i) + '-' + to_string(j);
        if (memo.find(key) != memo.end()) return memo[key];

        unordered_set<string> temp;
        if (s1[i - 1] == s2[j - 1]) {
            temp = findLcsSeq(i - 1, j - 1, s1, s2, dp);
            for (string lcs : temp) st.insert(lcs + s1[i - 1]);
        } else {
            if (dp[i - 1][j] == dp[i][j - 1]) {
                temp = findLcsSeq(i - 1, j, s1, s2, dp);
                st.insert(temp.begin(), temp.end());
                temp = findLcsSeq(i, j - 1, s1, s2, dp);
                st.insert(temp.begin(), temp.end());
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                temp = findLcsSeq(i - 1, j, s1, s2, dp);
                st.insert(temp.begin(), temp.end());
            } else {
                temp = findLcsSeq(i, j - 1, s1, s2, dp);
                st.insert(temp.begin(), temp.end());
            }
        }

        return memo[key] = st;
    }

    vector<string> allLCS(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp = bottomUp(s1, s2);
        
        memo.clear();
        
        unordered_set<string> result = findLcsSeq(n, m, s1, s2, dp);
        
        vector<string> vec(result.begin(), result.end());
        sort(vec.begin(), vec.end());
        print(vec);
        return vec;
    }
};

void doWork() {
    Solution sol;
    sol.allLCS("abaaa", "baabaca");
}
