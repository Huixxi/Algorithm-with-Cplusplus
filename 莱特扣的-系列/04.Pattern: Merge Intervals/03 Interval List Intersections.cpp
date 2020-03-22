class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if(A.size() == 0 || B.size() == 0)
            return res;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            if(A[i][0] > B[j][1]) {
                ++j;
                continue;
            }
            if(A[i][1] < B[j][0]) {
                ++i;
                continue;
            }
            vector<int> temp{max(A[i][0], B[j][0]), min(A[i][1], B[j][1])};
            res.push_back(temp);
            if(A[i][1] <= B[j][1]) 
                ++i;
            else
                ++j;
        }
        return res;
    }
};
