// https://cses.fi/problemset/task/1640/
#include <bits/stdc++.h>

using namespace std;

void doWork() {
    int n, x;
    cin >> n >> x;

    vector<int> vec(n);
    vector<pair<int, int>> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i].first;
		nums[i].second = i;
	}

    sort(nums.begin(), nums.end());
	int l = 0, r = n - 1;

    while (l < r) {
		int sum = nums[l].first + nums[r].first;
		if (sum == x) {
			cout << nums[l].second + 1 << " " << nums[r].second + 1 << endl;
			return;
		} else if (sum < x) {
			l++;
		} else if (sum > x) {
			r--;
		}
	}

    cout << "IMPOSSIBLE" << endl;
}
