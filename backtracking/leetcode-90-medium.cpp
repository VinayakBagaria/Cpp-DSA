#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(int start, vector<vector<int>>& result, vector<int>& nums, vector<int>& temp) {
        result.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }

            temp.push_back(nums[i]);
            solve(i+1, result, nums, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, result, nums, temp);
        sort(result.begin(), result.end());
        return result;
    }
};

void doWork() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    auto subsets = sol.subsetsWithDup(nums);

    int i = 0;
    for (auto sub : subsets) {
        i++;
        cout << "Subset " << i << endl;
        for (auto it : sub) cout << it << " ";
        cout << endl;
    }
}