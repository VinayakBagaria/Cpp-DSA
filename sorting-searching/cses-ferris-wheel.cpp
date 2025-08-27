// https://cses.fi/problemset/task/1090/
#include <bits/stdc++.h>

using namespace std;

void doWork() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (auto& it : vec) cin >> it;

    sort(vec.begin(), vec.end());
    int l = 0, r = n-1;
    int count = 0;

    while (l <= r) {
        if (vec[l] + vec[r] <= x) {
            l++;   
        }
        r--;
        count++;
    }

    cout << count << endl;
}
