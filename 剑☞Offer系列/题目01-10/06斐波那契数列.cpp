class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1, c;
        if(n == 0)
            return a;
        if(n == 1)
            return b;
        while(n > 1 && n--) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
