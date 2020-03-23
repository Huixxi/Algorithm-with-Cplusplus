class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int l = nums.size();
        for(int i = 0; i < l; ++i) {
            while(nums[i] != 0 && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i = 0; i < l; ++i) {
            if(nums[i] == 0)
                return i + 1;
        }
        return 0;
    }
};
