#include <bits/stdc++.h>

using namespace std;


string resultingString(string s) {
    stack<char> st;
    for (char c : s) {
        if (st.size() == 0) {
            st.push(c);
        } else {
            int top = st.top();
            int diff = abs(top - c);
            if (diff == 1 || diff == 25) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }   

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

void doWork() {
    cout << resultingString("zadb") << endl;
}