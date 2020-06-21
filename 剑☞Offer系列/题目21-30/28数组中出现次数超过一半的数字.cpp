class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // the most direct method is to use a map to count, but ..
        int majority = numbers[0], cnt = 1;
        for(int i = 1; i < numbers.size(); ++i) {
            if(numbers[i] == majority)   
                ++cnt;
            else {
                if(--cnt == 0) {
                    majority = numbers[i];
                    cnt = 1;
                }
            }
        }
        return majority;
    }
};
