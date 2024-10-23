// https://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <unordered_map>

using namespace std;

int spellCheck() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n != 5) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<char, int> original;
        for (char c : "Timur") {
            original[c]++;
        }

        bool found = true;
        for(char c : s) {
            if (original.find(c) == original.end() || original[c] == 0) {
                found = false;
                break;
            }

            original[c]--;
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}