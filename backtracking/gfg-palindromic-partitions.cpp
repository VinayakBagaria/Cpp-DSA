// https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    bool isPalin(string& s) {
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

    void solve(int i, vector<string>& curr, string& s, vector<vector<string>>& result) {
        if (i == s.size()) {
            result.push_back(curr);
            return;
        }

        string sub = "";
        for (int k = i; k < s.size(); k++) {
            sub += s[k];

            if (isPalin(sub)) {
                curr.push_back(sub);
                solve(k+1, curr, s, result);
                curr.pop_back();
            }
        }
    }

  public:
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(0, curr, s, result);
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
    string s = "geeks";
    print(sol.palinParts(s));

    cout << "-------" << endl;
    s = "abcba";
    print(sol.palinParts(s));
}

