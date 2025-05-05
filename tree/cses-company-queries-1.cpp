#include <bits/stdc++.h>

using namespace std;

int getResult(unordered_map<int, int> &mp, int employee, int levels) {
    while (levels > 0) {
        if (mp.find(employee) == mp.end()) {
            return -1;
        }

        employee = mp[employee];
        levels--;
    }

    return employee;
}

void doWork() {
    int n, q;
    cin >> n >> q;

    unordered_map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        int manager;
        cin >> manager;
        mp[i] = manager;
    }

    for (int i = 0; i < q; i++) {
        int employee, levels;
        cin >> employee >> levels;

        cout << getResult(mp, employee, levels) << endl;
    }
}