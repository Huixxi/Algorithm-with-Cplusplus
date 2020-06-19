class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        vector<int> flag_col(n, 1), flag_l45(2 * n - 1, 1), flag_r45(2 * n - 1, 1);
        helper(res, nQueens, flag_col, flag_l45, flag_r45, 0, n);
        return res;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& nQueens, vector<int>& flag_col, vector<int>& flag_l45, vector<int>& flag_r45, int row, int& n) {
        if(row == n) {
            res.push_back(nQueens);
            return;
        }
        for(int col = 0; col < n; ++col) {
            if(flag_col[col] && flag_l45[row + col] && flag_r45[n - 1 + col - row]) {
                flag_col[col] = flag_l45[row + col] = flag_r45[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                helper(res, nQueens, flag_col, flag_l45, flag_r45, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_l45[row + col] = flag_r45[n - 1 + col - row] = 1;
            }
        }
    }
};
