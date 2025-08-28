// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        unordered_map<char, int> want, mp;
        for (char& c : p) want[c]++;

        int need = want.size(), have = 0;
        int l = 0, r = 0;
        int minLen = 1e9, start = -1;
        
        while (r < s.size()) {
            mp[s[r]]++;
            if (mp[s[r]] == want[s[r]]) {
                have++;
            }

            while (have == need) {
                int currSize = r - l + 1;
                if (currSize < minLen) {
                    minLen = currSize;
                    start = l;
                }
                
                char lc = s[l];
                mp[lc]--;
                l++;
                
                if (mp[lc] < want[lc]) {
                    have--;
                }
            }

            r++;
        }
        
        return minLen == 1e9 ? "" : s.substr(start, minLen);
    }
};

void doWork() {
    Solution sol;
    string s = "timetopractice", p = "toc";
    cout << sol.smallestWindow(s, p) << endl;
    s = "zoomlazapzo", p = "oza";
    cout << sol.smallestWindow(s, p) << endl;
    s = "zoom", p = "zooe";
    cout << sol.smallestWindow(s, p) << endl;
}
