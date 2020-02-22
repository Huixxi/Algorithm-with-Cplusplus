class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        // 模拟过程
        if(n == 0)
            return -1;
        int tag[10000] = {0}, count = 0, i = 0, idx = 0;
        while(count != n - 1) {
            if(tag[idx % n] == 0) {
                if(i == m - 1) {
                    tag[idx % n] = 1;
                    ++count;
                    i = 0;
                }
                else{
                    ++i;
                }
            }
            ++idx;
        }
        for(int i = 0; i < n; ++i)
            if(!tag[i])
                return i;
    }
};
