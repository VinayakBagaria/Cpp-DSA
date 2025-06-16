#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordCount = words.size();
        int wordSize = words[0].size();
        int n = s.size();

        unordered_map<string, int> needWindow;
        for (string word : words) needWindow[word]++;

        vector<int> result;
        int limit = n - (wordCount * wordSize) + 1;

        for (int i = 0; i < limit; i++) {
            unordered_map<string, int> currWindow;
            int j = 0;

            while (j < wordCount) {
                string word = s.substr(i + j * wordSize, wordSize);
                if (needWindow.find(word) != needWindow.end()) {
                    currWindow[word]++;
                    if (currWindow[word] > needWindow[word]) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }

            if (j == wordCount) {
                result.push_back(i);
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