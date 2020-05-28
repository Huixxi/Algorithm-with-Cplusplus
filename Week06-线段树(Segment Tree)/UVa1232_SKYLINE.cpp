// solution from https://upcommons.upc.edu/bitstream/handle/2117/104161/127102.pdf?sequence=1&isAllowed=y
#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)
#define right(x) (x<<1)+1

const int MAXN = 1e5+10;
vector<int> segTree;  // minheightTree
vector<int> lazyTree;  // maxheightTree

void updateSegTreeLazy(int height, int qlow, int qhigh, int low, int high, int pos) {
    if(qlow >= high || qhigh <= low)
        return;
    lazyTree[pos] = max(lazyTree[pos], height);
    if(qlow <= low && qhigh >= high) {
        segTree[pos] = max(segTree[pos], height);
    }
    else {
        int mid = low + (high - low) / 2;
        updateSegTreeLazy(height, qlow, qhigh, low, mid, left(pos));
        updateSegTreeLazy(height, qlow, qhigh, mid, high, right(pos));
        segTree[pos] = max(segTree[pos], min(segTree[left(pos)], segTree[right(pos)]));
    }

}

int rangeQueryLazy(int height, int qlow, int qhigh, int low, int high, int pos) {
    if(qlow >= high || qhigh <= low)
        return 0;

    if(segTree[pos] > height)
        return 0;

    if(lazyTree[pos] <= height)
        return min(qhigh, high) - max(qlow, low);

    int mid = low + (high - low) / 2;
    int vl = rangeQueryLazy(height, qlow, qhigh, low, mid, left(pos));
    int vr = rangeQueryLazy(height, qlow, qhigh, mid, high, right(pos));
    return vl + vr;

}

int main() {
    int n, t, l, r, h, m = 1;
    cin >> n;
    while(n--) {
        m = 1;
        while (m < MAXN ) m *= 2;
        segTree = lazyTree = vector<int>(2 * m, 0) ;
        cin >> t;
        int sum = 0;
        while(t--) {
            cin >> l >> r >> h;
            sum += rangeQueryLazy(h, l, r, 0, m, 1);
            updateSegTreeLazy(h, l, r, 0, m, 1);
        }
        cout << sum << endl;
    }
}
