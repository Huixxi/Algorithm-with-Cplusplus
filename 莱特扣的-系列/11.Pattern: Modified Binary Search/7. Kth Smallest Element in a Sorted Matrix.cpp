class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int num = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while(j >= 0 && matrix[i][j] > mid)
                    --j;
                num += j + 1;
            }
            if(num < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};
