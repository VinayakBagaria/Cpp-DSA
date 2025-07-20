// https://leetcode.com/problems/split-array-by-prime-indices/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> v(n + 1, 1);
        v[0] = 0;
        v[1] = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (v[i]) {
                for (int j = i * i; j <= n; j+=i) v[j] = 0;
            }
        }
        return v;
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> p = sieve(n);
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (p[i]) sum1 += nums[i];
            else sum2 += nums[i];
        }

        return abs(sum1 - sum2);
    }
};

void doWork() {
    Solution obj;
    vector<int> vec = {2,3,4};
    cout << obj.splitArray(vec) << endl;
    vec = {-1,5,7,0};
    cout << obj.splitArray(vec) << endl;
}