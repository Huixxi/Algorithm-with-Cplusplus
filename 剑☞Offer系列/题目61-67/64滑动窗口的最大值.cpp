class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() == 0 || size < 1 || size > num.size())
            return res;
        deque<int> dk;
        int i;
        for(i = 0; i < size; ++i) {
            while(!dk.empty() && num[i] > num[dk.back()])
                dk.pop_back();
            dk.push_back(i);
        }
        for(; i < num.size(); ++i) {
            res.push_back(num[dk.front()]);
            while(!dk.empty() && num[i] >= num[dk.back()])
                dk.pop_back();
            if(!dk.empty() && i - dk.front() >= size)
                dk.pop_front();
            dk.push_back(i);
        }
        res.push_back(num[dk.front()]);
        return res;
    }
};
