class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        int flag = 0;
        if(newInterval[1] < intervals[0][0]) {
            res.push_back(newInterval);
            flag = 2;
        }
        for(int i = 0; i < intervals.size(); ++i) {
            if((flag == 0 || flag == 2) && (newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0])) {
                res.push_back(intervals[i]);
                if(i < intervals.size() - 1 && newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i+1][0])
                    flag = 1;
            }
            else if(flag == 1 && newInterval[0] > intervals[i][1] || newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                flag = 2;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                flag = 1;
            }
        }
        if(flag != 2)
            res.push_back(newInterval);
        return res;
    }
};
