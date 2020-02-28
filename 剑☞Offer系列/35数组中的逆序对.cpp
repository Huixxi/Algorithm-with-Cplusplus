class Solution {
public:
    // 归并排序算法思想： https://www.cnblogs.com/wanglei5205/p/8893700.html
    int count = 0;
    int InversePairs(vector<int> data) {
        if(data.size()) {
            MergeSort(data, 0, data.size() - 1);
        }
        return count;
    }
private:
    void MergeSort(vector<int>& v, int l, int r) {
        if(l < r) {
            int m = (l + r) >> 1;
            MergeSort(v, l, m);
            MergeSort(v, m + 1, r);
            Merge(v, l, m, r);
        }
    }
    void Merge(vector<int>& v, int l, int m, int r) {
        vector<int> t;
        int i = l;
        int j = m + 1;
        while(i <= m && j <= r) {
            if(v[i] > v[j]) {
                t.push_back(v[j++]);
                count = (count + m - i + 1) % 1000000007;
            }
            else
                t.push_back(v[i++]);
        }
        while(i <= m)
            t.push_back(v[i++]);
        while(j <= r)
            t.push_back(v[j++]);
        for(i = 0; i < t.size(); ++i)
            v[l + i] = t[i];
    }
};
