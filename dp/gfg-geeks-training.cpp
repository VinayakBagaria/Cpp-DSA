// https://www.geeksforgeeks.org/problems/geeks-training/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int solve(int i, int last, vector<vector<int>>& arr, vector<unordered_map<int, int>>& dp) {
        if (i == arr.size()) {
            return 0;
        }

        if (dp[i][last] != 0) return dp[i][last];

        int maxi = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            if (j == last) continue;
            maxi = max(maxi, arr[i][j] + solve(i + 1, j, arr, dp));
        }
        return dp[i][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        vector<unordered_map<int, int>> dp(arr.size());
        return solve(0, -1, arr, dp);
    }
};


void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << sol.maximumPoints(vec) << endl;
    vec = {{1,1,1}, {2,2,2}, {3,3,3}};
    cout << sol.maximumPoints(vec) << endl;
    vec = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    cout << sol.maximumPoints(vec) << endl;
    // cout << sol.bottomUp(2) << endl;
}