// https://leetcode.com/problems/merge-adjacent-equal-elements/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> vec;
        for (int i = 0; i < nums.size(); i++) {
            long curr = nums[i];
            while (vec.size() && vec.back() == curr) {
                curr *= 2;
                vec.pop_back();
            }
            vec.push_back(curr);
        }
        return vec;
    }
};

void print(vector<long long> vec) {
    for (auto it : vec) cout << it << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<int> nums;
    nums = {3,1,1,2};
    print(sol.mergeAdjacent(nums));
    nums = {2,2,4};
    print(sol.mergeAdjacent(nums));
    nums = {3,7,5};
    print(sol.mergeAdjacent(nums));
    nums = {2,1,1,2};
    print(sol.mergeAdjacent(nums));
}
