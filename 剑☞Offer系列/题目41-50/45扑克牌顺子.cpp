class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5)  // 注意
            return false;
        sort(numbers.begin(), numbers.end());
        int i, sum = 0;
        for(i = 4; i > 0 && numbers[i-1]; --i) {
            if(numbers[i] == numbers[i-1])
                return false;
            sum += numbers[i] - numbers[i-1];
        }
        if(sum > 4)
            return false;
        return true;
    }
};
