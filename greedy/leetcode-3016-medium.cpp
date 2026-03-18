// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec(26);
        for (char c : word) vec[c - 'a']++;

        sort(vec.begin(), vec.end(), greater<int>());

        int i = 0;
        int res = 0;

        while (i < vec.size() && vec[i] != 0) {
            int multiplier = 1 + (i / 8);
            res += (vec[i] * multiplier);
            i++;
        }
        return res;
    }
};

void doWork() {
    Solution sol;
    cout << sol.minimumPushes("abcde") << endl;
    cout << sol.minimumPushes("aabbccddeeffgghhiiiiii") << endl;
    cout << sol.minimumPushes("hiknogatpyjzcdbe") << endl;
    cout << sol.minimumPushes("avghdcyinjmbopwtrfslzkuxeq") << endl;
}
