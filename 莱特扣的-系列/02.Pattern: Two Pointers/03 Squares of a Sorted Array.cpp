class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int i = 0, j = A.size() - 1, t = A.size() - 1;
        while(t >= 0) {
            if(A[i]*A[i] < A[j]*A[j]) {
                res[t] = A[j]*A[j];
                --j;
            }
            else {
                res[t] = A[i]*A[i];
                ++i;
            } 
            --t;   
        }
        return res;
    }
};
