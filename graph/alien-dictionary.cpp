// https://neetcode.io/problems/foreign-dictionary
#include <bits/stdc++.h>

using namespace std;

class Solution {
  typedef unordered_map<int, vector<int>> at;
  typedef vector<int> vt;
    
  private:
    vt topo(vt& indegree, at& adj, unordered_set<int>& valid) {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (valid.find(i) != valid.end() && indegree[i] == 0) {
                q.push(i);
            }
        }

        vt result;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            
            for (auto it : adj[curr]) {
                indegree[it]--;
                
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return result;
    }


  public:
    string findOrder(vector<string> &words) {
        at adj;
        vt indegree(26, 0);
        unordered_set<int> valid;

        for (auto word : words) {
            for (char ch : word) {
                valid.insert(ch - 'a');
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            int j = 0;
            int minLength = min(w1.size(), w2.size());
            while (w1[j] == w2[j] && j < minLength) {
                j++;
            }
            
            if (j < minLength) {
                int c1 = w1[j] - 'a';
                int c2 = w2[j] - 'a';
                adj[c1].push_back(c2);
                indegree[c2]++;
            } else if (w1.size() > w2.size()) {
                return "";
            }
        }

        vt result = topo(indegree, adj, valid);

        string ans = "";
        if (result.size() < valid.size()) {
            return ans;
        }
        
        for (int it : result) {
            ans += char(it + 'a');
        }
        
        return ans;
    }
};

void doWork() {
    Solution sol = Solution();
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout << sol.findOrder(words) << endl;

    words = {"caa", "aaa", "aab"};
    cout << sol.findOrder(words) << endl;

    words = {"ab", "cd", "ef", "ad"};
    cout << sol.findOrder(words) << endl;

    words = {"abc","bcd","cde"};
    cout << sol.findOrder(words) << endl;

    words = {"wrtkj","wrt"};
    cout << sol.findOrder(words) << endl;
}