class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int ll = intervals.size();
        int res = 0;
        if(ll == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for(int i = 1; i < ll; ++i) {
            if(end > intervals[i][0]) {
                intervals[i][1] = min(intervals[i][1], end);
                ++res;
            }
            end = intervals[i][1];
        }
        return res;
    }
};
