/*
 用两次二分搜索：
 第一次用来找翻转有序数组的中轴点(值最小的点)的下标
 第二次则直接在有序数组中搜索target
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        int lo = 0, hi = n - 1;
        // 第一次二分搜索
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(nums[mid] < nums[hi]) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        // cout << lo << endl;
        // 第二次二分搜索
        if(target <= nums[n-1])
            return binarySearch(nums, target, lo, n - 1);
        else
            return binarySearch(nums, target, 0, lo - 1);
    }
     
    int binarySearch(vector<int>& nums, int target, int lo, int hi) {
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[lo] == target) return lo;
            if(nums[hi] == target) return hi;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target) 
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        return nums[lo] == target ? lo : -1;
    }
};
