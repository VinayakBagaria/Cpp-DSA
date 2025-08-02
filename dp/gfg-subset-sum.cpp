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
};

void doWork() {
    Solution sol;
    vector<int> vec = {3, 34, 4, 12, 5, 2};
    cout << sol.isSubsetSum(vec, 9) << endl;
    vec = {3, 34, 4, 12, 5, 2};
    cout << sol.isSubsetSum(vec, 30) << endl;
    cout << sol.isSubsetSum(vec, 2) << endl;
}
