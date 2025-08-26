// https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int isPossible(vector<int>& arr, int k, int target) {
        int count = 0;
        int bouq = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= target) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                bouq++;
                count = 0;
            }
        }
        
        return bouq;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int reqd = k * m;
        if (reqd > arr.size()) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid) >= m) {
                high = mid - 1;
                result = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {3, 4, 2, 7, 13, 8, 5};
    cout << sol.minDaysBloom(vec, 2, 3) << endl;
    vec = {5, 5, 5, 5, 10, 5, 5};
    cout << sol.minDaysBloom(vec, 3, 2) << endl;
    vec = {1, 10, 3, 10, 2};
    cout << sol.minDaysBloom(vec, 2, 3) << endl;
}
