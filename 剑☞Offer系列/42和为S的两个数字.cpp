class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        for(int i : array) {
            for(int j = array.size() - 1; array[j] >= sum - i; --j) {
                if(array[j] == sum - i) {
                    res.push_back(i);
                    res.push_back(array[j]);
                    return res;
                }
            }
        }和为S的两个数字
    }
};
