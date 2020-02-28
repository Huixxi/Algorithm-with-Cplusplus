class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        vector<bool> flags(rows * cols, 0);
        bool res = true;
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j) {
                if(dfs(matrix, flags, rows, cols, i, j, str))
                    return true;
            }
        return false;
    }
private:
    bool dfs(char*& matrix, vector<bool>& flags, int& rows, int& cols, int i, int j, char*& str) {
        if(*str == '\0') 
            return true;
        bool res = false;
        if(i >= 0 && i < rows && j >= 0 && j < cols && !flags[i * cols + j] && matrix[i * cols + j] == *str) {
            flags[i * cols + j] = 1;
            ++str;
            res = dfs(matrix, flags, rows, cols, i + 1, j, str) ||
                  dfs(matrix, flags, rows, cols, i - 1, j, str) ||
                  dfs(matrix, flags, rows, cols, i, j + 1, str) ||
                  dfs(matrix, flags, rows, cols, i, j - 1, str);
            if(!res) {
                --str;
                flags[i * cols + j] = 0;
            }
        }
        return res;
    }
};
