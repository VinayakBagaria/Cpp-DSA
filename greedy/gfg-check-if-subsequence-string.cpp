// https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool solve(int i, int j, string& s1, string& s2) {
        if (i == s1.size()) {
            return true;
        }
        
        if (j == s2.size()) {
            return false;
        }
        
        if (s1[i] == s2[j]) {
            return solve(i + 1, j + 1, s1, s2);
        }
        return solve(i, j + 1, s1, s2);
    }
  
    bool isSubSeq(string s1, string s2) {
        return solve(0, 0, s1, s2);
    }

    bool isSubSeqIter(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) i++;
            j++;
        }
        
        return i == s1.size();
    }
};

void doWork() {
    Solution sol;
    cout << sol.isSubSeqIter("AXY", "YADXCP") << endl;
    cout << sol.isSubSeqIter("gksrek", "geeksforgeeks") << endl;
}
