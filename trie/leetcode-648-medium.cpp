// https://leetcode.com/problems/replace-words/description/
#include <bits/stdc++.h>

using namespace std;

struct trieNode {
    bool isEnd;
    trieNode* children[26];
};

trieNode* getNode() {
    trieNode* node = new trieNode();
    node->isEnd = false;
    for (int i = 0; i < 26; i++) node->children[i] = nullptr;
    return node;
}

class Trie {
    trieNode* root;

    public:
        Trie() {
            root = getNode();
        }

        void insert(string& word) {
            trieNode* crawl = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (crawl->children[idx] == nullptr) {
                    crawl->children[idx] = getNode();
                }
                crawl = crawl->children[idx];
            }
            crawl->isEnd = true;
        }

        string shortestRoot(string& word) {
            trieNode* crawl = root;
            string matched = "";

            for (char ch : word) {
                int idx = ch - 'a';
                if (crawl->children[idx] == nullptr) {
                    return word;
                }
                
                matched += ch;
                crawl = crawl->children[idx];
                if (crawl->isEnd) {
                    return matched;
                }
            }
            return word;
        }
};


class Solution {
public:
    string replaceWords(vector<string> dictionary, string sentence) {
        stringstream ss(sentence);
        string word;

        Trie trie;
        for (string &d : dictionary) trie.insert(d);

        string output = "";
        while (getline(ss, word, ' ')) {
            output += trie.shortestRoot(word) + " ";
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
