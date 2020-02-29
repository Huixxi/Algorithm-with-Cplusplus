class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;
        return 2 * jumpFloorII(number - 1);
    }
    // 循环解法
    /*
    int jumpFloorII(int number) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i < number; ++i) {
            int sum = 1;
            for(int j = i - 1; j >= 0; --j)
                sum += res[j];
            res.push_back(sum);
        }
        return res[number-1];
    }
    */
};
