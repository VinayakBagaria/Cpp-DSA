// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getCost(vector<int>& prices, int k) {
        int l = 0, r = prices.size() - 1;
        int sum = 0;
        while (l <= r) {
            sum += prices[l];
            l++;
            r -= k;
        }
        return sum;
    }
  
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int mini = getCost(prices, k);
        sort(prices.begin(), prices.end(), greater<int>());
        int maxi = getCost(prices, k);
        return {mini, maxi};
    }
};

void printOut(vector<int> vec) {
    cout << vec[0] << " " << vec[1] << endl;
}

void doWork() {
    Solution sol;
    vector<int> vec = {3, 2, 1, 4};
    printOut(sol.minMaxCandy(vec, 2));
    vec = {3, 2, 1, 4, 5};
    printOut(sol.minMaxCandy(vec, 4));
    vec = {9, 13, 4, 17, 7, 13};
    printOut(sol.minMaxCandy(vec, 1));
    vec = {3, 16, 9, 1};
    printOut(sol.minMaxCandy(vec, 3));
}
