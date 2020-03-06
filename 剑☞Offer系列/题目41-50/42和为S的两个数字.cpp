class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int i = 0, j = array.size() - 1;
        while(i < j) {
            if(array[j] == sum - array[i]) {
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
            if(array[j] > sum - array[i])
                --j;
            else
                ++i;
        }
        return res;
    }
};
