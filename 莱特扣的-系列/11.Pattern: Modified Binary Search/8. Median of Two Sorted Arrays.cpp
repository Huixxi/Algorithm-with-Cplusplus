class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size();
        int y = nums2.size();
        int l = 0;
        int r = x;
        while(l <= r) {
            int leftpartX = l + (r - l) / 2;
            int leftpartY = (x + y + 1) / 2 - leftpartX;
            
            int maxleftX = leftpartX == 0 ? INT_MIN : nums1[leftpartX - 1];
            int minrightX = leftpartX == x ? INT_MAX : nums1[leftpartX];
            
            int maxleftY = leftpartY == 0 ? INT_MIN : nums2[leftpartY - 1];
            int minrightY = leftpartY == y ? INT_MAX : nums2[leftpartY];
            
            if(maxleftX <= minrightY && maxleftY <= minrightX) {
                if((x + y) % 2 == 0)
                    return double((max(maxleftX, maxleftY) + min(minrightX, minrightY))) / 2;
                else
                    return max(maxleftX, maxleftY);
            }
            else if(maxleftX > minrightY)
                r = leftpartX - 1;
            else
                l = leftpartX + 1;
        }
        return 0.0;
    }
};
