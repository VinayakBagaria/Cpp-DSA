// https://leetcode.com/problems/maximum-strength-of-a-group/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long prod = 1;
        bool hasPositive = false;

        for (int num : nums) {
            if (num > 0) {
                prod *= num;
                hasPositive = true;
            } else if (num < 0) {
                pq.push(num);
            }
        }

        // If I have no positive with me and count of -ves <= 1 -> meaning either 1 or no 0
        // If we have 1 negative number only in the array, then pq.size() == nums.size() - 
        //          So, return pq.top()
        if (!hasPositive && pq.size() <= 1) {
            return pq.size() == nums.size() ? pq.top() : 0;
        }

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            prod *= first * second;
        }

        return prod;
    }
};

void doWork() {
    Solution sol;
    vector<int> nums = {3,-1,-5,2,5,-9};
    cout << sol.maxStrength(nums) << endl;
    nums = {-4,-5,-4};
    cout << sol.maxStrength(nums) << endl;
    nums = {0,-1};
    cout << sol.maxStrength(nums) << endl;
    nums = {9,6,3};
    cout << sol.maxStrength(nums) << endl;
    nums = {0,1};
    cout << sol.maxStrength(nums) << endl;
    nums = {-9};
    cout << sol.maxStrength(nums) << endl;
    nums = {1};
    cout << sol.maxStrength(nums) << endl;
}
