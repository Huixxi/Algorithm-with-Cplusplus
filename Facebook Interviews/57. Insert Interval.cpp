class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> tmp;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }
        tmp = newInterval;
        for(; i < intervals.size(); ++i) {
            if(tmp[0] <= intervals[i][1] && tmp[1] >= intervals[i][0]) {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
            }
            else {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }
        res.push_back(tmp);
        return res;
    }
};
