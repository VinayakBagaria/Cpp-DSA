// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordCount = words.size();
        int wordLen = words[0].size();
        int n = s.size();

        unordered_map<string, int> needWindow;
        for (string word : words) needWindow[word]++;

        vector<int> result;

        // Sliding window length of wordCount * wordLen
        // If size of every word is 3, loop from 0, 1, 2.
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> currWindow;
            int count = 0;
            int l = i;

            for (int r = l; r < n; r += wordLen) {
                string word = s.substr(r, wordLen);

                if (needWindow.find(word) != needWindow.end()) {
                    currWindow[word]++;
                    count++;

                    // If current word count has exceeded, try shrinking from left
                    // Remove invalid words from count
                    while (currWindow[word] > needWindow[word]) {
                        string left = s.substr(l, wordLen);
                        currWindow[left]--;
                        count--;
                        l += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(l);
                    }
                } else {
                  currWindow.clear();
                  count = 0;
                  
                  // We didn't get r - r + wordLen string in the need window
                  // So, skip all words till r + wordLen

                  // Thus, skip all words from [i...r + wordLen] as they are invalid
                  // Reset the window to start all counting again
                  // Hence, we make l == r
                  l = r + wordLen;
                }
            }
        }

        return result;
    }
};

void printResult(vector<int> result) {
    for (int r : result) cout << r << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<string> words = {"foo","bar"};
    printResult(sol.findSubstring("barfoothefoobarman", words));
    printResult(sol.findSubstring("barfoot", words));
}