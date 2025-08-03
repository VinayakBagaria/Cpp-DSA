// https://leetcode.com/problems/assign-cookies/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gi = 0, si = 0;

        while (si < s.size() && gi < g.size()) {
            if (g[gi] <= s[si]) gi++;
            si++;
        }

        return gi;
    }
};

void doWork() {
    Solution sol;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << sol.findContentChildren(g, s) << endl;
    g = {1, 2};
    s = {1, 2, 3};
    cout << sol.findContentChildren(g, s) << endl;
}