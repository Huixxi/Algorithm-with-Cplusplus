class Solution {
public:
    int StrToInt(string str) {
        // 注意32整型的范围： -2^31 ~ 2^31-1
        long sum = 0, flag = 0;
        if(str[0] == '+' || str[0] == '-')
            flag = 1;
        for(int i = flag; i < str.length(); ++i) {
            if(str[i] > '9' || str[i] < '0')
                return 0;
            sum = 10 * sum + str[i] - '0';
        }
        if(flag == 1 && str[0] == '-')
            sum *= -1;
        if(sum < -(pow(2, 31)) || sum > pow(2, 31) - 1)
            return 0;
        return int(sum);
    }
};
