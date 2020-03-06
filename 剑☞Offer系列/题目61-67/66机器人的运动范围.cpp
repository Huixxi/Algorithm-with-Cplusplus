class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<int> vec(rows * cols, 0);
        return movingC(threshold, vec, 0, 0, rows, cols);
    }
    int movingC(int& threshold, vector<int>& vec, int i, int j, int& rows, int& cols) {
        int count = 0;
        if(i >= 0 && i < rows && j >= 0 && j < cols && !vec[i * cols + j] && (getSum(i) + getSum(j)) <= threshold) {
            vec[i * cols + j] = 1;
            count += 1 + 
                     movingC(threshold, vec, i + 1, j, rows, cols) +
                     movingC(threshold, vec, i - 1, j, rows, cols) +
                     movingC(threshold, vec, i, j + 1, rows, cols) +
                     movingC(threshold, vec, i, j - 1, rows, cols);
        }
        return count;
    }
    int getSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
