// https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int required = n / 2;
        if (n % 2 != 0) required++;
        
        vector<int> mods(n);
        for (int i = 0; i < n; i++) {
            mods[i] = arr[i] % k;
            if (mods[i] == 0) required--;
        }

        if (required <= 0) return 0;

        sort(mods.begin(), mods.end(), greater<int>());

        int need = 0;
        for (int i = 0; i < n; i++) {
            if (mods[i] == 0) break;
            need += k - mods[i];
            required--;
            if (required == 0) break;
        }
        return need;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {5, 6, 3, 2, 1};
    cout << sol.minSoldiers(vec, 2) << endl;
    vec = {3, 5, 6, 7, 9, 10};
    cout << sol.minSoldiers(vec, 4) << endl;
    vec = {1, 2, 6, 4, 5, 4, 6, 1, 4, 7};
    cout << sol.minSoldiers(vec, 2) << endl;
}