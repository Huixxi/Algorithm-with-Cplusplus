class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3)
            return res;
        int low = 1, high = 2;
        while(high > low && high <= sum / 2 + 1) {
            int temp = (low + high) * (high - low + 1) / 2;
            if(temp < sum)
                ++high;
            if(temp > sum)
                ++low;
            if(temp == sum) {
                vector<int> vec;
                for (int i = low; i <= high; ++i)
                    vec.push_back(i);
                res.push_back(vec);
                ++low;
            }
        }
        return res;
    } 
};
