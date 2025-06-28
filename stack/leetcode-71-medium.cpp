// https://leetcode.com/problems/simplify-path/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        // stack contains all folders, which will be separated by / at the end
        stack<string> st;

        for (int i = 0; i < n; i++) {
            // If a / is encountered, don't do anything with it in the stack
            if (path[i] == '/') continue;

            string curr = "";
            while(i < n && path[i] != '/') {
                curr += path[i];
                i++;
            }

            // Nothing to do if . is encountered
            if (curr == ".") continue;

            // If we need to go back, pop previous directory from the stack if possible
            if (curr == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(curr);
            }
        }

        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        // Case to handle "/.."
        if (result.size() == 0) result = "/";

        return result;
    }
};

void doWork() {
    Solution sol;
    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/.../a/../b/c/../d/./") << endl;
    cout << sol.simplifyPath("///TJbrd/owxdG//") << endl;
}