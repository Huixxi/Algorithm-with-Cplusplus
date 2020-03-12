class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int sum, minn = 10000;
        for(int i = 0; i < len - 2; ++i) {
            int l = i + 1;
            int r = len - 1;
            while(l < r) {
                if(minn == 0)
                    break;
                if(abs(target - nums[i] - nums[l] - nums[r]) < minn) {
                    minn = abs(target - nums[i] - nums[l] - nums[r]);
                    sum = nums[i] + nums[l] + nums[r];
                }
                if(nums[l] + nums[r] > target - nums[i]) 
                    --r;
                else 
                    ++l;
            }
        }
        return sum;
    }
};
