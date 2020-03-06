class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        // 丑数： 2*2*2*...*3*3*3....*5*5*5
        // https://segmentfault.com/a/1190000015753301 屌
        if(index < 7)
            return index;
        vector<int> res;
        res.push_back(1);
        int t1 = 0, t2 = 0, t3 = 0;
        for(int i = 1; i < index; ++i) {
            res.push_back(min(res[t1]*2, min(res[t2]*3, res[t3]*5)));
            if(res[i] == res[t1]*2)
                ++t1;
            if(res[i] == res[t2]*3)
                ++t2;
            if(res[i] == res[t3]*5)
                ++t3;
        }
        return res[index-1];
    }
};
