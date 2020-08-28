class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, n = A.size();
        for(j = 0; j < n; ++j) {
            if(A[j] == 0) --K;
            if(K < 0 && A[i++] == 0) ++K;
        }
        return j - i;
    }
};
