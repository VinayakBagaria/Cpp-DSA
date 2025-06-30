// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findCount(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        int n = nums2.size();
        long long count = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= 0) {
                int l = 0, r = n - 1;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long curr = 1LL * nums1[i] * nums2[mid];

                    if (curr <= midProduct) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                count += l;
            } else {
                int l = 0, r = n - 1;

                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long curr = 1LL * nums1[i] * nums2[mid];

                    if (curr <= midProduct) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                count += (n - l);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long countLteMid = findCount(nums1, nums2, mid);
            if (countLteMid < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};

void doWork() {
    Solution sol;
    vector<int> n1 = {2, 5}, n2 = {3, 4};
    cout << sol.kthSmallestProduct(n1, n2, 2) << endl;
    n1 = {-4,-2,0,3}, n2 = {2,4};
    cout << sol.kthSmallestProduct(n1, n2, 6) << endl;
    n1 = {-2,-1,0,1,2}, n2 = {-3,-1,2,4,5};
    cout << sol.kthSmallestProduct(n1, n2, 3) << endl;
}