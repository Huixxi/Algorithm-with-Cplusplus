class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        const int n = nums.size();
        if(n == 0) return res;
        // lower_bound of target
        int low = lower_bound(nums, target);
        // lower_bound of target + 1
        int high = lower_bound(nums, target + 1) - 1;
        
        if(low < n && nums[low] == target)
            return vector<int>{low, high};
        return res;
    }
    
    int lower_bound(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }
};
