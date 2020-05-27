#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)+1
#define right(x) (x<<1)+2

const int MAXN = 2e6;
int segTree[4*MAXN];
int lazyTree[4*MAXN];
int arr[MAXN];

void constructSegTree(int low, int high, int pos) {
    if(low == high) {
        segTree[pos] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    constructSegTree(low, mid, left(pos));
    constructSegTree(mid+1, high, right(pos));
    segTree[pos] = segTree[left(pos)] + segTree[right(pos)];
}

// F : 0, E : 1, I : 2
void updateSegTreeLazy(int op, int qlow, int qhigh, int low, int high, int pos) {
    if(lazyTree[pos] != -1) {
        if(lazyTree[pos] == 2) {
            segTree[pos] = (high - low + 1) - segTree[pos];
            if(low != high) {  // non-leaf nodes
                if(lazyTree[left(pos)] == -1)
                    lazyTree[left(pos)] = 2;
                else if(lazyTree[left(pos)] == 2)
                    lazyTree[left(pos)] = -1;
                else
                    lazyTree[left(pos)] = !lazyTree[left(pos)];

                if(lazyTree[right(pos)] == -1)
                    lazyTree[right(pos)] = 2;
                else if(lazyTree[right(pos)] == 2)
                    lazyTree[right(pos)] = -1;
                else
                    lazyTree[right(pos)] = !lazyTree[right(pos)];
            }
        }
        else { // F or E
            segTree[pos] = lazyTree[pos] * (high - low + 1);
            if(low != high) {  // non-leaf nodes
                lazyTree[left(pos)] = lazyTree[pos];
                lazyTree[right(pos)] = lazyTree[pos];
            }
        }
        lazyTree[pos] = -1;
    }

    if(qlow <= low && qhigh >= high) {
        if(op == 2) {
            segTree[pos] = (high - low + 1) - segTree[pos];
            if(low != high) {  // non-leaf nodes
                if(lazyTree[left(pos)] == -1)
                    lazyTree[left(pos)] = 2;
                else if(lazyTree[left(pos)] == 2)
                    lazyTree[left(pos)] = -1;
                else
                    lazyTree[left(pos)] = !lazyTree[left(pos)];

                if(lazyTree[right(pos)] == -1)
                    lazyTree[right(pos)] = 2;
                else if(lazyTree[right(pos)] == 2)
                    lazyTree[right(pos)] = -1;
                else
                    lazyTree[right(pos)] = !lazyTree[right(pos)];
            }
        }
        else { // F or E
            segTree[pos] = op * (high - low + 1);
            if(low != high) {  // non-leaf nodes
                lazyTree[left(pos)] = op;
                lazyTree[right(pos)] = op;
            }
        }
        return;
    }

    if(qlow > high || qhigh < low)
        return;

    int mid = low + (high - low) / 2;
    updateSegTreeLazy(op, qlow, qhigh, low, mid, left(pos));
    updateSegTreeLazy(op, qlow, qhigh, mid+1, high, right(pos));
    segTree[pos] = segTree[left(pos)] + segTree[right(pos)];

}

int rangeQueryLazy(int qlow, int qhigh, int low, int high, int pos) {
    if(lazyTree[pos] != -1) {
        if(lazyTree[pos] == 2) {
            segTree[pos] = (high - low + 1) - segTree[pos];
            if(low != high) {  // non-leaf nodes
                if(lazyTree[left(pos)] == -1)
                    lazyTree[left(pos)] = 2;
                else if(lazyTree[left(pos)] == 2)
                    lazyTree[left(pos)] = -1;
                else
                    lazyTree[left(pos)] = !lazyTree[left(pos)];

                if(lazyTree[right(pos)] == -1)
                    lazyTree[right(pos)] = 2;
                else if(lazyTree[right(pos)] == 2)
                    lazyTree[right(pos)] = -1;
                else
                    lazyTree[right(pos)] = !lazyTree[right(pos)];
            }
        }
        else { // F or E
            segTree[pos] = lazyTree[pos] * (high - low + 1);
            if(low != high) {  // non-leaf nodes
                lazyTree[left(pos)] = lazyTree[pos];
                lazyTree[right(pos)] = lazyTree[pos];
            }
        }
        lazyTree[pos] = -1;
    }
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qlow > high || qhigh < low)
        return 0;

    int mid = low + (high - low) / 2;
    int vl = rangeQueryLazy(qlow, qhigh, low, mid, left(pos));
    int vr = rangeQueryLazy(qlow, qhigh, mid+1, high, right(pos));
    return vl + vr;
}

int main() {
    int n, t, m, x = 1;
    map<char, int> mm = {{'F', 1}, {'E', 0}, {'I', 2}};
    cin >> n;
    while(--n >= 0) {
        memset(lazyTree, -1, sizeof(lazyTree));
        cin >> t;
        string str;
        while(--t >= 0) {
            int i;
            cin >> i;
            string p;
            cin >> p;
            while(--i >= 0) {
                str += p;
            }
        }
        int l = str.length();
        for(int i = 0; i < l; ++i)
            arr[i] = str[i] - '0';
        constructSegTree(0, l - 1, 0);
        cin >> m;
        char op;
        int low, high;
        int cnt = 1;
        cout << "Case " << x << ":" << endl;
        while(--m >= 0) {
            cin >> op >> low >> high;
            if(op != 'S')
                updateSegTreeLazy(mm[op], low, high, 0, l - 1, 0);
            else {
                cout << "Q" << cnt << ": " << rangeQueryLazy(low, high, 0, l - 1, 0) << endl;
                ++cnt;
            }
        }
        ++x;
    }
}
