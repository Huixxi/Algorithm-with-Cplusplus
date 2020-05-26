#include <bits/stdc++.h>
using namespace std;

#define left(x) (x<<1)+1
#define right(x) (x<<1)+2

const int MAXN = 1e5;
int segTree[4*MAXN];

void constructSegTree(int arr[], int low, int high, int pos) {
    if(low == high) {
        segTree[pos] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    constructSegTree(arr, low, mid, left(pos));
    constructSegTree(arr, mid+1, high, right(pos));
    segTree[pos] = max(segTree[left(pos)], segTree[right(pos)]);
}

int rangeQuery(int arr[], int qlow, int qhigh, int low, int high, int pos) {
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qlow > high || qhigh < low)
        return INT_MIN;

    int mid = low + (high - low) / 2;
    int vl = rangeQuery(arr, qlow, qhigh, low, mid, left(pos));
    int vr = rangeQuery(arr, qlow, qhigh, mid+1, high, right(pos));
    return max(vl, vr);
}

int main() {
    int n, t, i;
    while(cin >> n && n) {
        cin >> t;
        int arr[n]; cin >> arr[0];
        int starts[n]; starts[0] = 0;
        int freq[n]; freq[0] = 1;
        int s = 0, tmp = 0;
        for(i = 1; i < n; ++i) {
            cin >> arr[i];
            if(arr[i] == arr[i-1]) {
                starts[i] = starts[i-1];
                ++freq[s];
            }
            else {
                starts[i] = i;
                tmp = freq[s];
                while(s < i)
                    freq[s++] = tmp;
                freq[s] = 1;
            }
        }
        tmp = freq[s];
        while(s < i)
            freq[s++] = tmp;

//        for(int c = 0; c < n; ++c)
//            cout << arr[c] << " " << starts[c] << " " << freq[c] << endl;
        constructSegTree(freq, 0, n-1, 0);

        int qlow = 0, qhigh = 0;
        for(i = 0; i < t; ++i) {
            cin >> qlow >> qhigh;
            --qlow; --qhigh;
            if(arr[qlow] == arr[qhigh])
                cout << qhigh - qlow + 1 << endl;
            else {
                int kl = starts[qlow] + freq[qlow];
                int kr = qhigh - starts[qhigh] + 1;
                cout << max(max(kl - qlow, kr), rangeQuery(freq, kl, starts[qhigh] - 1, 0, n - 1, 0)) << endl;
            }
        }
    }
}
