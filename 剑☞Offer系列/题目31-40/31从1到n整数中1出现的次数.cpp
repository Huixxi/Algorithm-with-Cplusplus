class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        while(n) {
            int i = n;
            while(i) {
                if(i % 10 == 1)
                    ++count;
                i /= 10;
            }
            --n;
        }
        return count;
    }
};
