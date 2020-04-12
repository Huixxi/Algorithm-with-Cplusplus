class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        sort(nums.begin(), nums.end());
        int start;
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0 || nums[i] != nums[i-1]) start = 0;
            for(int end = res.size(); start < end; ++start) {
                vector<int> tmp = res[start];
                tmp.push_back(nums[i]);
                res.push_back(move(tmp));
            }
        }
        return res;
    }
};
