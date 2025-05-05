#include <bits/stdc++.h>

using namespace std;

void doWork() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> applicants(n);
    for (int &x : applicants) {
        cin >> x;
    }

    vector<int> flats(m);
    for (int &x : flats) {
        cin >> x;
    }

    sort(applicants.begin(), applicants.end());
    sort(flats.begin(), flats.end());

    int count = 0, l = 0, r = 0;
    while (l < n && r < m) {
        if (abs(applicants[l] - flats[r]) <= k) {
            count++;
            l++;
            r++;
        } else if (applicants[l] < flats[r]) {
            l++;
        } else {
            r++;
        }
    }
    cout << count << endl;
}