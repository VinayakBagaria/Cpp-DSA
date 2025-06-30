// https://leetcode.com/problems/word-ladder
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            string curr = q.front().first;
            int op = q.front().second;
            q.pop();

            if (curr == endWord) {
                return op;
            }

            for (int i = 0; i < curr.size(); i++) {
                string transform = curr;
                for (int j = 0; j < 26; j++) {
                    transform[i] = j + 'a';
                    if (st.find(transform) != st.end() && visited.find(transform) == visited.end()) {
                        visited.insert(transform);
                        q.push({transform, op+1});
                    }
                }
            }
        }

        return 0;
    }
};

void doWork() {
    Solution sol;
    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength("hit", "cog", wl) << endl;
    wl = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "log", wl) << endl;
}