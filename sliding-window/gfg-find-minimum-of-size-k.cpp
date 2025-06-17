// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                q.push(i);
            }
        }
        
        int n = arr.size();
        for (int l = 0; l + k <= n; l++) {
            int forward = l + k - 1;
            if (l > 0 && arr[forward] < 0) {
                q.push(forward);
            }
            
            if (q.size() > 0) {
                int index = q.front();
                result.push_back(arr[index]);
                if (l == index) q.pop();
            } else {
                result.push_back(0);
            }
        }
        
        return result;
    }
};

void print(vector<int> vec) {
    for (int it : vec) cout << it << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<int> vec = {-8, 2, 3, -6, 10};
    print(sol.firstNegInt(vec, 2));

    vec = {12, -1, -7, 8, -15, 30, 16, 28};
    print(sol.firstNegInt(vec, 3));
}