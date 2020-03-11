class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 1;
        if(nums.size() < 2)
            return nums.size();
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] != nums[i + 1]) {
                nums[length] = nums[i + 1];
                ++length;
            }
        }
        return length;
    }
};
