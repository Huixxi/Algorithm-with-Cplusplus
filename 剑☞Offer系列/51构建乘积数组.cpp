class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B = {};
        if(A.size() < 2)
            return B;
        int n = A.size();
        int l = 1, r = 1;
        B.push_back(l);
        for(int i = 1; i < n; ++i) {
            l *= A[i-1];
            B.push_back(l);
        }
        for(int j = n - 2; j >= 0; --j) {
            r *= A[j+1];
            B[j] *= r;
        }
        return B;
    }
};
