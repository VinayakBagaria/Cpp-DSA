// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int res = 0, count = 1;

        while (n >= 8) {
            n -= 8;
            res += count * 8;
            count++;
        }
        res += count * n;
        return res;
    }
};

void doWork() {
    Solution sol;
    cout << sol.minimumPushes("abcde") << endl;
    cout << sol.minimumPushes("xycdefghij") << endl;
}
