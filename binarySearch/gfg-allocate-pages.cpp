// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int isPossible(vector<int>& arr, int maxSum) {
        // at least one student
        int count = 1;
        int currSum = 0;

        for (int page : arr) {
            if (currSum + page > maxSum) {
                count++;
                currSum = page;
            } else {
                currSum += page;
            }
        }

        return count;
    }
  
    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If "mid" sum of books requires more students (> k)
            // Then meaning: I need more sum of books
            if (isPossible(arr, mid) > k) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1; // try smaller maxSum
            }
        }
        
        return result;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {12, 34, 67, 90};
    cout << sol.findPages(vec, 2) << endl;
    vec = {5, 17, 20};
    cout << sol.findPages(vec, 5) << endl;
}
