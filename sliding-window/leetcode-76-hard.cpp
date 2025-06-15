// https://leetcode.com/problems/minimum-window-substring/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> wantedWindow;
        for (char c : t) wantedWindow[c]++;

        int n = s.size();
        int have = 0, need = wantedWindow.size(), l = 0, minLen = INT_MAX;
        unordered_map<char, int> currWindow;
        int startIndex = -1;

        for (int r = 0; r < n; r++) {
            char right = s[r];
            currWindow[right]++;

            if (currWindow[right] == wantedWindow[right]) {
                have++;
            }

            while (have == need) {
                int currLen = r - l + 1;
                if (currLen < minLen) {
                    currLen = minLen;
                    startIndex = l;
                }

                char left = s[l];
                l++;
                currWindow[left]--;
                if (currWindow[left] < wantedWindow[left]) {
                    have--;
                }
            }
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

void doWork() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("aa", "aa") << endl;
    cout << sol.minWindow("a", "aa") << endl;
}