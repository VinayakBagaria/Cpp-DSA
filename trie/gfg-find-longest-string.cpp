// https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1
#include <bits/stdc++.h>

using namespace std;

struct trieNode {
    bool isEndOfWord;
    trieNode* children[26];
};

trieNode* getNode() {
    trieNode* node = new trieNode();
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) node->children[i] = NULL;
    return node;
}

class Trie {
    trieNode* root;

  public:
    Trie() {
        root = getNode();
        root->isEndOfWord = true;
    }

    void insert(string word) {
        trieNode* crawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        
        crawl->isEndOfWord = true;
    }

    string recurse(trieNode* node, string curr) {
        string maxi = curr;

        for (int i = 0; i < 26; i++) {
            trieNode* child = node->children[i];
            if (child != NULL && child->isEndOfWord) {
                string depth = curr;
                depth += (char) (i + 'a');
                string result = recurse(child, depth);
                if (result.size() > maxi.size()) {
                    maxi = result;
                }
            }
        }

        return maxi;
    }

    string findLongestString() {
        return recurse(root, "");
    }
};

class Solution {
  public:
    string longestString(vector<string> &arr) {
        Trie trie;
        for (string word : arr) trie.insert(word);

        return trie.findLongestString();
    }
};

void doWork() {
    Solution sol;
    vector<string> vec = {"p", "pr", "pro", "probl", "problem", "pros", "process", "processor"};
    cout << sol.longestString(vec) << endl;
    vec = {"ab", "a", "abc", "abd"};
    cout << sol.longestString(vec) << endl;
}