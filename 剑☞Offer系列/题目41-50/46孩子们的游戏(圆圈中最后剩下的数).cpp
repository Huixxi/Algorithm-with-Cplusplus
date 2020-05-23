class Solution {
public:
    /* 
    The position returned by josephus(n - 1, k) is adjusted because the recursive call  
    josephus(n - 1, k) considers the original position k % n + 1 as position 1 */
    int LastRemaining_Solution(int n, int m) {
        if (n == 0)
            return -1;
        if (n == 1) // LastRemaining_Solution(1, m) == 0，幸存者下标为0
            return 0; 
        return (LastRemaining_Solution(n - 1, m) + m) % n; 
        /*
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
        */
    }
};
