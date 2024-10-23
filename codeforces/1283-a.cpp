// https://codeforces.com/problemset/problem/1283/A
#include <iostream>

using namespace std;

int minutesBefore() {
    int t;
    cin >> t;

    while(t--) {
        int h, m;
        cin >> h >> m;
        cout << ((24 * 60) - ((60 * h) + m)) << endl;
    }

    return 0;
}