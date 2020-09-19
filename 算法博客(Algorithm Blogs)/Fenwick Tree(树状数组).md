## Binary Indexed Tree(Fenwick Tree树状数组)
一种非常NB的数据结构，用来快速计算前缀和。时间复杂度：建树`O(nlogn)`，更新`O(logn)`，查询`O(logn)`。   

教程： 
* [Fenwick Tree or Binary Indexed Tree](https://www.youtube.com/watch?v=CWDQJGaN1gY)
* [Tutorial: Binary Indexed Tree (Fenwick Tree)](https://www.youtube.com/watch?v=v_wj_mOAlig)

算法题：
* 
* 
* 
* 
* 
* 

Binary Indexed Tree的基础实现：
```c++
#include <bits/stdc++.h>
using namespace std;

class BinIdxTree {
private:
    vector<int> biTree;
    int capacity;
public:
    explicit BinIdxTree(int n) : capacity(n + 1) {
        biTree = vector<int>(capacity, 0);
    }

    ~BinIdxTree() = default;

    void bulidBinIdxTree(const vector<int>& arr) {
        int n = arr.size();
        for(int i = 1; i <= n; ++i) {
            updateBinIdxTree(i, arr[i-1]);
        }
    }

    void updateBinIdxTree(int idx, int val) {
        while(idx < capacity) {
            biTree[idx] += val;
            idx = getNext(idx);
        }
    }

    int getSum(int idx) {
        ++idx;
        int sum = 0;
        while(idx > 0) {
            sum += biTree[idx];
            idx = getParent(idx);
        }
        return sum;
    }

    int getParent(int index) {
        return index - (index & -index);
    }

    int getNext(int index) {
        return index + (index & -index);
    }
};

int main() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    BinIdxTree biT(n);
    biT.bulidBinIdxTree(arr);
    for(int i = 0; i < n; ++i) {
        cout << biT.getSum(i) << endl;
    }
}

/*
 * output:
 * 1
 * 3
 * 6
 * 10
 * 15
 * 21
 * 28
 */
```
