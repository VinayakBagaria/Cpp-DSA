// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        // P1 + P2 + ... + PnumFriends = n (word.size)
        // If P1 = max, then P2, P3 + ... PnumFriends should all be 1
        // i.e.., greedily give others lowest value
        // P1max + (numFriends - 1) * 1 = n
        // P1max + numFriends - 1 = n
        // P1max = n - numFriends + 1

        // So if numFriends = 1, then the word itself is the max string

        if (numFriends == 1) {
            return word;
        }

        int n = word.size();
        int m = n - numFriends + 1;

        string res;
        for (int i = 0; i < n; i++) {
            string sub = word.substr(i, m);
            res = max(res, sub);
        }
        return res;
    }
};

void doWork() {
    Solution sol = Solution();
    cout << sol.answerString("dbca", 2) << endl;

    cout << sol.answerString("gggg", 4) << endl;

    cout << sol.answerString("gh", 1) << endl;

    cout << sol.answerString("dah", 3) << endl;

    cout << sol.answerString("aann", 2) << endl;
}