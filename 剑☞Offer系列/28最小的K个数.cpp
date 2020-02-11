class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> mm;
        for(auto& i : numbers) {
            if(mm.find(i) != mm.end())
                ++mm[i];
            else
                mm[i] = 1;
            if(mm[i] > numbers.size() / 2)
                return i;
        }
        return 0;
    }
};
