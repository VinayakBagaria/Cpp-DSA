// https://codeforces.com/problemset/problem/158/A
#include <iostream>
#include<vector>

using namespace std;

int nextRound() {
    int n,k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int ans = 0;
    int ref = vec[k - 1];

    for (int val : vec) {
        if (val >= ref && val > 0) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}