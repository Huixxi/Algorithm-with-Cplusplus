class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(0, nums, {});
        return res;
    }
    
    void helper(int i, vector<int>& nums, vector<int> subset) {
        res.push_back(subset);
        for(int j = i; j < nums.size(); ++j) {
            subset.push_back(nums[j]);
            helper(j + 1, nums, subset);
            subset.pop_back();
        }
    }
};
