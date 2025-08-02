// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == arr.size()) return false;
        if (sum < 0) return false;
        if (arr[i] == sum) return true;

        if (dp[i][sum] != -1) return dp[i][sum];

        bool take = solve(i + 1, sum - arr[i], arr, dp);
        bool notTake = solve(i + 1, sum, arr, dp);

        return dp[i][sum] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(0, sum, arr, dp);
    }

    bool bottomUp(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
            if (arr[i] <= sum) dp[i][arr[i]] = true;
        }

        for (int i = n-2; i >= 0; i--) {
            for (int s = 1; s <= sum; s++) {
                bool take = false;
                if (s >= arr[i]) take = dp[i + 1][s - arr[i]];

                bool notTake = dp[i + 1][s];
                dp[i][s] = take || notTake;
            }
        }

        return dp[0][sum];
    }

    bool spaceBottomUp(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1), curr(sum + 1);

        // Sum 0 is always possible
        prev[0] = true;

        // This is is because the last element can be the sum and no else would be required after that + not possible after that even
        if (arr[n-1] <= sum) prev[arr[n-1]] = true;

        for (int i = n-2; i >= 0; i--) {
            curr[0] = true;
            for (int s = 1; s <= sum; s++) {
                bool take = false;
                if (s >= arr[i]) take = prev[s - arr[i]];

                bool notTake = prev[s];
                curr[s] = take || notTake;
            }
            prev = curr;
        }

        return prev[sum];
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {3, 34, 4, 12, 5, 2};
    cout << sol.isSubsetSum(vec, 9) << endl;
    cout << sol.bottomUp(vec, 9) << endl;
    cout << sol.spaceBottomUp(vec, 9) << endl;
    vec = {3, 34, 4, 12, 5, 2};
    cout << sol.isSubsetSum(vec, 30) << endl;
    cout << sol.bottomUp(vec, 30) << endl;
    cout << sol.spaceBottomUp(vec, 30) << endl;
    cout << sol.isSubsetSum(vec, 2) << endl;
    cout << sol.bottomUp(vec, 2) << endl;
    cout << sol.spaceBottomUp(vec, 2) << endl;
    vec = {6, 3, 7, 4, 1, 6, 4, 3, 7};
    cout << sol.isSubsetSum(vec, 4) << endl;
    cout << sol.bottomUp(vec, 4) << endl;
    cout << sol.spaceBottomUp(vec, 4) << endl;
}
