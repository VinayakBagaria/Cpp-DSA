// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int> nums) {
        // We store what elements and how much count in left and right part
        // Store frequencies dynamically as we go through the array
        unordered_map<int, int> left;
        unordered_map<int, int> right;

        // Initially, all the elements belong to right map. That is L=[]; R=[0,n-1]
        for (int x : nums) {
            right[x]++;
        }

        int n = nums.size();

        // "i" is different split points
        // Since we are splitting now, right map should decrease and left map should increase the count for the current element.
        // We imagine a number being removed from right side and given to left side.
        // Now, if this number crosses the half length size on both sides of the split, then success.
        // Left = [0,i] => Size i+1
        // Right = [i+1,n-1] => Size n-i-1
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            right[curr]--;
            left[curr]++;

            bool isLeftDominant = left[curr] * 2 > (i + 1);
            bool isRightDominant = right[curr] * 2 > (n - i - 1);

            if (isLeftDominant && isRightDominant) {
                return i;
            }
        }

        return -1;
    }
};

void doWork() {
    Solution sol;
    cout << sol.minimumIndex({1, 2, 2, 2}) << endl;
    cout << sol.minimumIndex({2,1,3,1,1,1,7,1,2,1}) << endl;
}
