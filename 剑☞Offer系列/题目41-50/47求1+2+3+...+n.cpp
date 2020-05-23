class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        bool ans = (n > 0) && (sum += Sum_Solution(n - 1));
        return sum;
    }
};
