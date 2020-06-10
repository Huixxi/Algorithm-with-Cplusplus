class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        int sign = n < 0 ? -1 : 1;
        long m = long(n) * sign;
        double res = 1.0;
        while(m) {
            if(m % 2 == 1)
                res *= x;
            x *= x;
            m /= 2;
        }
        return sign == 1 ? res : double(1 / res);
    }
};
