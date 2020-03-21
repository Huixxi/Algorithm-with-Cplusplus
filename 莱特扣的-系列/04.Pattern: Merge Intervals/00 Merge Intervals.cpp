class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int i;
        for(i = 1; i < intervals.size(); ++i) {
            while(i < intervals.size() && intervals[i][0] <= intervals[i-1][1]) {
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                ++i;
            }
            res.push_back(intervals[i-1]);
        }
        if(intervals.back() != res.back())
            res.push_back(intervals.back());
        return res;
    }
};
