// https://www.geeksforgeeks.org/problems/coin-piles5152/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];

        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            int maxAllowed = arr[i] + k;
            int maxIndex = upper_bound(arr.begin(), arr.end(), maxAllowed) - arr.begin();
            
            int prev = i > 0 ? prefix[i-1] : 0;
            int allowedSum = (n - maxIndex) * maxAllowed;
            int greaterSum = prefix[n - 1] - prefix[maxIndex - 1];
            int totalToRemove = prev + (greaterSum - allowedSum);
            mini = min(mini, totalToRemove);
        }

        return mini;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {1, 5, 1, 2, 5, 1};
    cout << sol.minimumCoins(vec, 3) << endl;
}
