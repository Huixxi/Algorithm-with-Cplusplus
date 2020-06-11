class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a[0]];
            --m[a[1]];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};
