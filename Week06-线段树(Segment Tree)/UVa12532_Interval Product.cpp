#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)+1
#define right(x) (x<<1)+2

const int MAXN = 1e5 + 10;
int segTree[4*MAXN];
int flg[MAXN];

void constructSegTree(int low, int high, int pos) {
    if(low == high) {
        segTree[pos] = flg[low];
        return;
    }
    int mid = low + (high - low) / 2;
    constructSegTree(low, mid, left(pos));
    constructSegTree(mid+1, high, right(pos));
    segTree[pos] = segTree[left(pos)] * segTree[right(pos)];
}

void updateSegTree(int val, int qlow, int qhigh, int low, int high, int pos) {
    if(qlow <= low && qhigh >= high) {
        segTree[pos] = val;
        flg[low] = val;
        return;
    }

    if(qlow > high || qhigh < low)
        return;

    int mid = low + (high - low) / 2;
    updateSegTree(val, qlow, qhigh, low, mid, left(pos));
    updateSegTree(val, qlow, qhigh, mid+1, high, right(pos));
    segTree[pos] = segTree[left(pos)] * segTree[right(pos)];

}

int rangeQuery(int qlow, int qhigh, int low, int high, int pos) {
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qlow > high || qhigh < low)
        return 1;

    int mid = low + (high - low) / 2;
    int vl = rangeQuery(qlow, qhigh, low, mid, left(pos));
    int vr = rangeQuery(qlow, qhigh, mid+1, high, right(pos));
    return vl * vr;
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        int arr;
        for(int i = 0; i < n; ++i) {
            cin >> arr;
            flg[i] = arr > 0 ? 1 : (arr == 0 ? 0 : -1);
        }
        constructSegTree(0, n - 1, 0);
        char op;
        int idx, val;
        while(--k >= 0) {
            cin >> op >> idx >> val;
            if(op == 'C') {
                int tmp = val > 0 ? 1 : (val == 0 ? 0 : -1);
                if (tmp != flg[idx-1])
                    updateSegTree(tmp, idx-1, idx-1, 0, n - 1, 0);
            }
            else {
                int sig = rangeQuery(idx-1, val-1, 0, n - 1, 0);
                char res = sig == 1 ? '+' : (sig == 0 ? '0' : '-');
                cout << res;
            }
        }
        cout << endl;
    }
}
