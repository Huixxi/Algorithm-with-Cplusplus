class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k)
            return vector<int>();
        // 红黑树 最大堆 O(logn)
        multiset<int, greater<int>> res;
        for(int i = 0; i < input.size(); ++i) {
            if(i < k)
                res.insert(input[i]);
            else {
                if(input[i] < *res.begin()) {
                    res.erase(*res.begin());
                    res.insert(input[i]);
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
