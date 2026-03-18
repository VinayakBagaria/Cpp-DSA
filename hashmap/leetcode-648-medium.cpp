// https://leetcode.com/problems/replace-words/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string> dictionary, string sentence) {
        stringstream ss(sentence);
        string output = "";
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        string word;
        while (getline(ss, word, ' ')) {
            string curr = "";
            for (char c : word) {
                curr += c;
                if (st.count(curr)) {
                    break;
                }
            }

            output += curr + " ";
        }

        output.pop_back();
        return output;
    }
};


void doWork() {
    Solution sol;
    cout << sol.replaceWords({"cat","bat","rat"}, "the cattle was rattled by the battery") << endl;
    cout << sol.replaceWords({"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs") << endl;
}
