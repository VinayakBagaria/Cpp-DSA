// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxChar = 0, res = 0;
        unordered_map<char, int> mp;

        for (r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            maxChar = max(maxChar, mp[s[r]]);

            int windowLen = r - l + 1;
            if (windowLen - maxChar > k) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};


void doWork() {
    Solution sol;
    cout << sol.characterReplacement("ABAB", 2) << endl;
    cout << sol.characterReplacement("AABABBA", 1) << endl;
}