// https://cses.fi/problemset/task/3220/
#include <bits/stdc++.h>

using namespace std;


long long slidingWindowSum(vector<int> &vec, int k) {
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += vec[i];
    }

    long long result = sum;
    for (int i = k; i < vec.size(); i++) {
        sum -= vec[i-k];
        sum += vec[i];
        result ^= sum;
    }

    return result;
}

void doWork() {
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> vec(n);
    vec[0] = x;
    for (int i = 1; i < n; i++) {
        vec[i] = (1LL * a * vec[i-1] + b) % c;
    }

    cout << slidingWindowSum(vec, k) << endl;
}