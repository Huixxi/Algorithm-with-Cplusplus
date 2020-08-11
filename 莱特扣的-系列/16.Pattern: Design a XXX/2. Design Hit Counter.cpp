#include <bits/stdc++.h>
using namespace std;

class HitCounter {
    vector<int> times, hits;
    int during;

public:
    HitCounter(int n) : during(n) {
        times.resize(n);
        hits.resize(n);
    }

    void hit(int timestamp) {
        int idx = timestamp % during;
        if(times[idx] != timestamp) {
            times[idx] = timestamp;
            hits[idx] = 1;
        }
        else 
            ++hits[idx];
    }

    int getHits(int timestamp) {
        int res = 0;
        for(int i = 0; i < during; ++i) {
            if(timestamp - times[i] < during)
                res += hits[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
