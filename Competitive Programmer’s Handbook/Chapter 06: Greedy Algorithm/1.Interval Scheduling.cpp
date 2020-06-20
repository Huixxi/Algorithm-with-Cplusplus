class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // Greedy, always select the next possible event that ends as early as possible. 
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 1;
        vector<int> p = pairs[0];
        for(int i = 1; i < pairs.size(); ++i) {
            if(pairs[i][0] > p[1]) {
                ++cnt;
                p = pairs[i];
            }
        }
        return cnt;
    }
};
