// https://leetcode.com/problems/smallest-number-in-infinite-set/
#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
public:
    int currSmallest;
    set<int> addedBack;

    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        if (!addedBack.empty()) {
            int x = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return x;
        }
        return currSmallest++;
    }
    
    void addBack(int num) {
        if (num < currSmallest) {
            addedBack.insert(num);
        }
    }
};


void doWork() {
    SmallestInfiniteSet s;
    s.addBack(2);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    s.addBack(1);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
}
