class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int r, c, rows, cols;
        rows = array.size();
        cols = array[0].size();
        r = 0;
        c = cols - 1;
        while(r < rows && c >= 0) {
            if(array[r][c] == target)
                return true;
            if(array[r][c] > target)
                --c;
            else
                ++r;
        }
        return false;
    }
};
