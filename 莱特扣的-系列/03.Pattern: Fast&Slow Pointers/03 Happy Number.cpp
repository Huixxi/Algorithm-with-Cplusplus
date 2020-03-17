class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while(slow != fast);
        return slow == 1;
    }
    int squareSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
