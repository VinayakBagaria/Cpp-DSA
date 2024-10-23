// https://codeforces.com/problemset/problem/263/A
#include <iostream>
#include<vector>

using namespace std;

int beautifulMatrix() {
    int n = 5;
    int x;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;

            if (x == 1) {
                int ans = abs(i - 3) + abs(j - 3);
                cout << ans << endl;
            }
        }
    }

    return 0;
}