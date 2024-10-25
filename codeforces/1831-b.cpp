// https://codeforces.com/contest/1831/problem/B
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<int, int> calcRun(int n, vector<int> vec) {
    unordered_map<int, int> mp;
    int count = 1;
    mp[vec[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i] == vec[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        mp[vec[i]] = max(count, mp[vec[i]]);
    }

    return mp;
}

int arrayMerging() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a1(n);
        vector<int> a2(n);
        set<int> allData;

        for(int i = 0; i < n; i++) {
            cin >> a1[i];
            allData.insert(a1[i]);
        }
        for(int i = 0; i < n; i++) {
            cin >> a2[i];
            allData.insert(a2[i]);
        }

        unordered_map<int, int> mp1 = calcRun(n, a1);
        unordered_map<int, int> mp2 = calcRun(n, a2);

        int count = 0;
        for (int el : allData) {
            int tc = mp1[el] + mp2[el];
            count = max(count, tc);
        }

        cout << count << endl;
    }

    return 0;
}