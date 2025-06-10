// https://leetcode.com/problems/find-peak-element/description
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        if (nums[0] > nums[1]) {
            return 0;
        }

        if (nums[n-1] > nums[n-2]) {
            return n-1;
        }

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            }

            if (nums[mid-1] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

void doWork() {
    Solution s;
    cout << s.findPeakElement({1,2,3,1}) << endl;
    cout << s.findPeakElement({1,2,1,3,5,6,4}) << endl;
}
