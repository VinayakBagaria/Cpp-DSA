// https://leetcode.com/problems/restore-ip-addresses/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(string& s, int i, vector<string>& path, vector<string>& res) {
        if (path.size() == 4) {
            if (i == s.size()) {
                res.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3]);
            }
            return;
        }

        int num = 0;
        for (int j = i; j < s.size(); j++) {
            num = (num * 10) + (s[j] - '0');
            if (num > 255) break;
            if (s[i] == '0' && j > i) break;

            path.push_back(to_string(num));
            solve(s, j + 1, path, res);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12) return {};

        vector<string> path;
        vector<string> res;
        solve(s, 0, path, res);
        return res;
    }
};

void print(vector<string> subsets) {
    for (auto sub : subsets) {
        cout << sub << " ";
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    print(sol.restoreIpAddresses("25525511135"));
    print(sol.restoreIpAddresses("0000"));
    print(sol.restoreIpAddresses("101023"));
}
