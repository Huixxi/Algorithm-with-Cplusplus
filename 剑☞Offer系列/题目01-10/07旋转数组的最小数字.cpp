class Solution {
public:
    int minNumberInRotateArray(vector<int>& rotateArray) {
        const int n = rotateArray.size();
        int l = 0, r = n - 1, mid = 0;
        while(l < r) {
            mid = l + (r - l) / 2;
            if(rotateArray[mid] < rotateArray[r])
                r = mid;
            else 
                l = mid + 1;
        }
        return rotateArray[l];
    }
};
