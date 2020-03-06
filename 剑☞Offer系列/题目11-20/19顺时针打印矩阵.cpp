class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;
        vector<int> res;
        while(l < r && t < b) {
            for(int i = l; i < r; ++i)
                res.push_back(matrix[t][i]);
            for(int i = t; i < b; ++i)
                res.push_back(matrix[i][r]);
            for(int i = r; i > l; --i)
                res.push_back(matrix[b][i]);
            for(int i = b; i > t; --i)
                res.push_back(matrix[i][l]);
            ++l;
            --r;
            ++t;
            --b;
        }
        if(l == r && t == b)
            res.push_back(matrix[t][l]);
        if(l == r && t < b)
            for(int i = t; i <= b; ++i)
                res.push_back(matrix[i][l]);
        if(l < r && t == b)
            for(int i = l; i <= r; ++i)
                res.push_back(matrix[t][i]);
        return res;
    }
};
