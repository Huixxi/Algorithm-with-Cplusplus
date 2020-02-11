class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        // 遇到和为负数就重新开始
        int mx = -1000, sum = 0;
        for(auto& i : array) {
            sum += i;
            mx = max(mx, sum);
            if(sum <= 0) 
                sum = 0;
        }
        return mx;
    }
};
