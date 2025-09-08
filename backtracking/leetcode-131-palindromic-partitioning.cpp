// https://leetcode.com/problems/palindrome-partitioning/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(int i, string& s, vector<string>& curr, vector<vector<string>>& result) {
        if (i == s.size()) {
            result.push_back(curr);
            return;
        }

        string sub = "";
        for (int j = i; j < s.size(); j++) {
            sub += s[j];
            if (isPalindrome(sub)) {
                curr.push_back(sub);
                solve(j + 1, s, curr, result);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(0, s, curr, result);
        return result;
    }
};

void print(vector<vector<string>> result) {
    for (auto row : result) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    print(sol.partition("aab"));
}
