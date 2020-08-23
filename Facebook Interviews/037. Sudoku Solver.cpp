class Solution {
public:
    vector<vector<int>> rows, cols, blks;
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9, vector<int>(10));
        cols = vector<vector<int>>(9, vector<int>(10));
        blks = vector<vector<int>>(9, vector<int>(10));
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    int bx = i / 3;
                    int by = j / 3;
                    rows[i][n] = 1;
                    cols[j][n] = 1;
                    blks[bx * 3 + by][n] = 1;
                }
            }
        }
        doSudoku(board, 0, 0);
    }
    
    bool doSudoku(vector<vector<char>>& board, int i, int j) {
        if(i == 9)
            return true;
        
        int nj = (j + 1) % 9;
        int ni = nj == 0 ? i + 1 : i;
        
        if(board[i][j] != '.')
            return doSudoku(board, ni, nj);
        
        for(int n = 1; n <= 9; ++n) {
            if(!rows[i][n] && !cols[j][n] && !blks[(i / 3) * 3 + j / 3][n]) {
                rows[i][n] = 1;
                cols[j][n] = 1;
                blks[(i / 3) * 3 + j / 3][n] = 1;
                board[i][j] = n + '0';
                if(doSudoku(board, ni, nj))
                    return true;
                rows[i][n] = 0;
                cols[j][n] = 0;
                blks[(i / 3) * 3 + j / 3][n] = 0;
                board[i][j] = '.';
            }
        }
        return false;
    }
};
