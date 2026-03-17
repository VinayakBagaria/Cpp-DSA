// https://leetcode.com/problems/word-pattern/description/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
       stringstream ss(s);
       string word;
       int i = 0;

       unordered_map<string, char> mp1;
       unordered_map<char, string> mp2;

       while (getline(ss, word, ' ')) {
        if (i >= pattern.size()) return false;

        char ch = pattern[i];
        i++;
        if (mp1.find(word) != mp1.end()) {
            if (mp1[word] != ch) {
                return false;
            }
        }
        if (mp2.find(ch) != mp2.end()) {
            if (mp2[ch] != word) {
                return false;
            }
        }
        mp1[word] = ch;
        mp2[ch] = word;
       }

       return i == pattern.size();
    }
};

void doWork() {
    Solution sol;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl;
}
