// https://leetcode.com/problems/simplify-path/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        st.push("/");

        int i = 0;
        while (i < n) {
            string curr = "";

            while(i < n && path[i] != '/') {
                curr += path[i];
                i++;
            }

            if (curr == "..") {
                if (st.size() > 1) {
                    st.pop();
                    st.pop();
                }
            } else if (curr.size() > 0 && curr != ".") {
                st.push(curr);
                st.push("/");
            }


            while (i < n && path[i] == '/') {
                i++;
            }
        }

        if (st.size() > 1 && st.top() == "/") {
            st.pop();
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

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