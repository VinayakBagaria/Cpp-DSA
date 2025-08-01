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

    int bottomUp(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(arr.size(), vector<int>(3, 0));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 3; last++) {
                int maxi = 0;
                for (int task = 0; task < arr[day].size(); task++) {
                    if (task == last) continue;
                    maxi = max(maxi, arr[day][task] + dp[day-1][task]);
                }
                dp[day][last] = maxi;
            }
        }

        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }

    int spaceBottomUp(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> next(3, 0), prev(3, 0);

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 3; last++) {
                int maxi = 0;
                for (int task = 0; task < arr[day].size(); task++) {
                    if (task == last) continue;
                    maxi = max(maxi, arr[day][task] + prev[task]);
                }
                next[last] = maxi;
            }
            prev = next;
        }

        return max(prev[0], max(prev[1], prev[2]));
    }
};


void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << sol.maximumPoints(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{1,1,1}, {2,2,2}, {3,3,3}};
    cout << sol.maximumPoints(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    cout << sol.maximumPoints(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
}