class Solution {
public:
    void sortColors(vector<int> &nums) {
        int r = 0, w = 0, b = nums.size() - 1;
        while(w <= b) {
            int temp = nums[w];
            if(nums[w] == 0) {
                nums[w] = nums[r];
                nums[r] = temp;
                ++r;
                ++w;
            }
            else if(nums[w] == 2) {
                nums[w] = nums[b];
                nums[b] = temp;
                --b;
            }
            else
                ++w;
        }
    }
};
