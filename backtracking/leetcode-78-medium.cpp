#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(int i, vector<vector<int>>& result, vector<int>& temp, const vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, result, temp, nums);
        temp.pop_back();

        solve(i+1, result, temp, nums);
    }

public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, result, temp, nums);
        sort(result.begin(), result.end());
        return result;
    }
};

void doWork() {
    Solution sol;
    auto subsets = sol.subsets({1, 2, 3});

    int i = 0;
    for (auto sub : subsets) {
        i++;
        cout << "Subset " << i << endl;
        for (auto it : sub) cout << it << " ";
        cout << endl;
    }
}