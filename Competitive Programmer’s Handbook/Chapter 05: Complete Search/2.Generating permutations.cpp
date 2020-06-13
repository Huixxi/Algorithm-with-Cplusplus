class Solution {
public:
    vector<vector<int>> res;
    vector<int> perm;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> chosen(n, false);
        helper(nums, chosen);
        return res;
    }
    
    void helper(vector<int>& nums, vector<bool>& chosen) {
        if(perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(chosen[i])
                continue;
            chosen[i] = true;
            perm.push_back(nums[i]);
            helper(nums, chosen);
            perm.pop_back();
            chosen[i] = false;
        }
    }
};
