class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0 || intervals[0].size() == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= tmp[1] && intervals[i][1] >= tmp[0]) {
                tmp[0] = min(intervals[i][0], tmp[0]);
                tmp[1] = max(intervals[i][1], tmp[1]);
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
