// https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        // Find all primes till nums[x] for x in range [0, n-1]
        int maxi = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> primes = sieve(maxi);

        // For each multiplier of nums[i], we need to get its index to jump to that point
        // Lets say nums[i] = 2 and max(nums) = 8 --->
        // therefore in next iteration, we need to go to all multiples of 2 till 8
        // Next time: Indices where 2, 4, 6, 8 reside in nums
        unordered_map<int, vector<int>> valToIndices;
        for (int i = 0; i < n; i++) {
            valToIndices[nums[i]].push_back(i);
        }

        // steps, index
        queue<pair<int, int>> q;
        // If an index is visited, it means we have encountered it via a smaller route before hand
        // So no need to process that route again
        vector<bool> vis(n, false);
        q.push({0, 0});
        vis[0] = true;

        // Once a number is used, don't do it again in future.
        // Since for that number, we should have calculated its multipliers from nums
        // and tried traversing them
        unordered_set<int> usedPrimes;

        while (!q.empty()) {
            int steps = q.front().first, i = q.front().second;
            q.pop();

            if (i == n-1) return steps;

            if (i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = true;
                q.push({steps+1, i+1});
            }

            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = true;
                q.push({steps+1, i-1});
            }

            int curr = nums[i];
            // If current number is a prime, we need all other multipliers in the array
            // and visit those multipliers if not visited already
            // For a multiplier, there might be multiple indices - so visit each of them if not already done
            if (primes[curr] && usedPrimes.find(curr) == usedPrimes.end()) {
                usedPrimes.insert(curr);
                for (int j = curr; j <= maxi; j += curr) {
                    if (valToIndices.find(j) == valToIndices.end()) continue;

                    for (int idx : valToIndices[j]) {
                        if (!vis[idx]) {
                            vis[idx] = true;
                            q.push({steps+1, idx});
                        }
                    }
                }
            }
        }

        return -1;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {1,2,4,6};
    cout << sol.minJumps(vec) << endl;
    vec = {2,3,4,7,9};
    cout << sol.minJumps(vec) << endl;
    vec = {4,6,5,8};
    cout << sol.minJumps(vec) << endl;
    vec = {4,56,62,57,33,63,30,44};
    cout << sol.minJumps(vec) << endl;
    vec = {7,5,7};
    cout << sol.minJumps(vec) << endl;
}