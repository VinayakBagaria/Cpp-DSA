#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef pair<string, vector<string>> PP;

  public:
    vector<vector<string>> findLadders(string startWord, string endWord,
                                         vector<string>& wordList) {
        queue<PP> q;
        unordered_set<string> wl(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        
        q.push({startWord, {startWord}});

        int mini = INT_MAX;
        vector<vector<string>> result;
        
        while (!q.empty()) {
            int level = q.size();

            unordered_set<string> localVisited;
            
            for (int k = 0; k < level; k++) {
                auto [curr, path] = q.front();
                q.pop();
                int currPathSize = path.size();
                
                if (curr == endWord) {
                    if (currPathSize <= mini) {
                        if (currPathSize < mini) {
                            result.clear();
                            mini = currPathSize;
                        }
                        result.push_back(path);
                    }
                    continue;
                }
                
                for (int i = 0; i < curr.size(); i++) {
                    string temp = curr;
                    for (int j = 0; j < 26; j++) {
                        temp[i] = j + 'a';
                        
                        if (wl.count(temp) && !visited.count(temp)) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            q.push({temp, newPath});
                            localVisited.insert(temp);
                        }
                    }
                }
            }

            for (string w : localVisited) {
                visited.insert(w);
            }
        }
        
        return result;
    }
};

void print(vector<vector<string>> result) {
    for (auto row : result) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
    print(sol.findLadders("hit", "cog", wl));
    wl = {"hot","dot","dog","lot","log"};
    print(sol.findLadders("hit", "cog", wl));
}
