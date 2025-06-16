// https://leetcode.com/problems/letter-case-permutation/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(int i, string& s, string curr, vector<string>& result) {
        if (i == s.size()) {
            result.push_back(curr);
            return;
        }

        if (s[i] >= 'A' && s[i] <= 'Z') {
            solve(i + 1, s, curr + (char) tolower(s[i]), result);
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            solve(i + 1, s, curr + (char) toupper(s[i]), result);
        }

        solve(i + 1, s, curr + s[i], result);
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        solve(0, s, "", result);
        return result;
    }
};

void print(vector<string> subsets) {
    int i = 0;
    for (auto sub : subsets) {
        i++;
        cout << "Subset " << i << endl;
        for (auto it : sub) cout << it << " ";
        cout << endl;
    }
}

void doWork() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    print(sol.letterCasePermutation("a1b2"));
}
