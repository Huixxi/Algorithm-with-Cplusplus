class Solution {
public:
    double Power(double base, int exponent) {
        // 快速幂，注意指数的正负
        double res = 1.0;
        int f = exponent > 0 ? 1 : -1;
        exponent = abs(exponent);
        while(exponent) {
            if(exponent & 1)
                res *= base;
            base *= base;
            exponent >>= 1;
        }
        return f == 1 ? res : double(1 / res);
    }
};
