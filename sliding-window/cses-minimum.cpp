// https://cses.fi/problemset/task/3221/
#include <bits/stdc++.h>

using namespace std;


long long slidingWindowMinimum(vector<int> &vec, int k) {
    // increasing queue
    deque<int> deq;
    long long result = 0;


    for (int i = 0; i < vec.size(); i++) {
        // 1. Remove smaller index elements as they are now not
        // valid for this window
        while (deq.size() > 0 && deq.front() <= i - k) {
            deq.pop_front();
        }

        // 2. Remove any element in this queue which is greater
        // than current element
        while (deq.size() > 0 && vec[i] < vec[deq.back()]) {
            deq.pop_back();
        }

        deq.push_back(i);
        
        if (i >= k-1) {
            result ^= vec[deq.front()];
        }
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

    cout << slidingWindowMinimum(vec, k) << endl;
}