class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
    
    void helper(vector<int>& nums, int k) {
        if(k == nums.size()) {
            res.push_back(subset);
            return;
        }
        helper(nums, k + 1);
        subset.push_back(nums[k]);
        helper(nums, k + 1);
        subset.pop_back();
    }
};
