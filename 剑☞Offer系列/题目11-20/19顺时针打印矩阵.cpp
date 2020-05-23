class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int nr = matrix.size(); 
        if(nr == 0) return res;
        int nc = matrix[0].size();
        if(nc == 0) return res;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> nSteps{nc, nr - 1};
        int idir = 0;
        int ir = 0, ic = -1;
        while(nSteps[idir % 2]) {  // 偶数方向（左右）改变ic，奇数方向（上下）改变ir
            for(int i = 0; i < nSteps[idir % 2]; ++i) {
                ir += dirs[idir][0];
                ic += dirs[idir][1];
                res.push_back(matrix[ir][ic]);
            }
            --nSteps[idir % 2];
            idir = (idir + 1) % 4;
        }
        return res;
    }
};
