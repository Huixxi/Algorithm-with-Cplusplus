class Solution {
public:
    int rectCover(int number) {
        int a = 1, b = 1, c;
        if(number == 0)
            return 0;
        if(number == 1)
            return b;
        for(int i = 2; i <= number; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
