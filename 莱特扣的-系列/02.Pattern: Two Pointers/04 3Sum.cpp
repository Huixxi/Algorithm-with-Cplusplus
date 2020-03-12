class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int nz = nums.size();
        if(nz < 3)
            return res;
        sort(nums.begin(), nums.end());
        int l, r;
        vector<int> vec(3);
        for(int i = 0; i < nz - 2 && nums[i] <= 0; ++i) {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            l = i + 1;
            r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] == -nums[i]) {
                    vec[0] = nums[i];
                    vec[1] = nums[l];
                    vec[2] = nums[r];
                    if(res.empty() || vec != res.back())
                        res.push_back(vec);
                    ++l;
                    --r;
                }
                else if(nums[l] + nums[r] < -nums[i])
                    ++l;
                else
                    --r;
            }
        }
        return res;
    }
};
