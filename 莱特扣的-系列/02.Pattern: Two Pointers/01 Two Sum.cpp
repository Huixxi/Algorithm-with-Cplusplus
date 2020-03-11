class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mm;
        for(int i = 0; i < nums.size(); ++i) {
            if(mm.find(nums[i]) != mm.end()) {
                res.push_back(mm[nums[i]]);
                res.push_back(i);
                return res;
            }
            else
                mm[target - nums[i]] = i;
        }
        return res;
    }
};
