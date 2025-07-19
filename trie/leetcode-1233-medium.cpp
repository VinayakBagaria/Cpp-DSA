// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    bool isEnd;
    // Instead of TrieNode* children[26], for each node - we are storing the folder name
    // Different nodes get created if "/" is coming in b/w them
    unordered_map<string, TrieNode*> children;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->isEnd = false;
    return node;
}

class Trie {
    TrieNode* root;

  public:
    Trie() {
        root = getNode();
    }

    void insert(string& word) {
        TrieNode* crawl = root;
        string currFolder = "";

        for (int i = 0; i < word.size(); i++) {
            // Ignore 1st slash which prefixes every folder path
            if (i == 0) continue;

            char ch = word[i];
            // If current is /, we must have a string which is the present folder name
            // Reset the folder name after operations are done to create its sub-tree
            if (ch == '/') {
                if (crawl->children[currFolder] == NULL) {
                    crawl->children[currFolder] = getNode();
                }
                crawl = crawl->children[currFolder];
                currFolder = "";
            } else {
                currFolder += ch;
            }
        }

        // Insert the last folder to the tree
        if (crawl->children[currFolder] == NULL) {
            crawl->children[currFolder] = getNode();
        }
        crawl = crawl->children[currFolder];

        crawl->isEnd = true;
    }

    void searchAllEnds(TrieNode* crawl, string curr, vector<string>& result) {
        if (crawl->isEnd) {
            result.push_back(curr);
            return;
        }

        for (auto& it : crawl->children) {
            string depth = curr + "/" + it.first;
            searchAllEnds(it.second, depth, result);
        }
    }

    vector<string> searchAllEndsEntry() {
        vector<string> result;
        searchAllEnds(root, "", result);
        return result;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for (string& f : folder) trie.insert(f);
        return trie.searchAllEndsEntry();
    }
};

void print(vector<string> subsets) {
    for (auto sub : subsets) {
        cout << sub << " ";
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<string> vec = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    print(sol.removeSubfolders(vec));
    vec = {"/a","/a/b/c","/a/b/d"};
    print(sol.removeSubfolders(vec));
    vec = {"/a/b/c","/a/b/ca","/a/b/d"};
    print(sol.removeSubfolders(vec));
}
