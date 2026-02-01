// https://leetcode.com/problems/design-ride-sharing-system/
#include<bits/stdc++.h>

using namespace std;

class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> waitingRiders;
    unordered_set<int> cancelledRiders;

    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        waitingRiders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if (drivers.empty()) {
            return {-1, -1};
        }

        while (!riders.empty()) {
            int riderId = riders.front();
            riders.pop();
            if (cancelledRiders.count(riderId)) {
                continue;
            } else {
                int driver = drivers.front();
                drivers.pop();
                waitingRiders.erase(riderId);
                return {driver, riderId};
            }
        }

        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if (waitingRiders.count(riderId)) {
            cancelledRiders.insert(riderId);
        }
    }
};

void print(vector<int> vec) {
    for (int it : vec) cout << it << " ";
    cout << endl;
}

void doWork() {
    RideSharingSystem r;
    // r.addRider(3);
    // r.addDriver(2);
    // r.addRider(1);
    // print(r.matchDriverWithRider());
    // r.addDriver(5);
    // r.cancelRider(3);
    // print(r.matchDriverWithRider());
    // print(r.matchDriverWithRider());

    r.addRider(8);
    r.addDriver(8);
    r.addDriver(6);
    print(r.matchDriverWithRider());
    r.addRider(2);
    r.cancelRider(2);
    print(r.matchDriverWithRider());
}