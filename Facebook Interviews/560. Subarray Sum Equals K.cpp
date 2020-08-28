class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> mp; mp[0] = 1;
        for(auto n : nums) {
            sum += n;
            if(mp.count(sum - k) != 0)
                res += mp[sum - k];
            ++mp[sum];
        }
        return res;
    }
};
