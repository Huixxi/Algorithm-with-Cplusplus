class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int l = nums.size();
        vector<int> res;
        res.reserve(l);
        for(int i = 0; i < l; ++i) {
            while(nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i = 0; i < l; ++i) {
            if(nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};
