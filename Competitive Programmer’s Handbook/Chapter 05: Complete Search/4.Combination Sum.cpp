class Solution {
public:
    vector<int> combs;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        search(candidates, 0, target);
        return res;
    }
    
    void search(vector<int>& cands, int k, int tar) {
        if(tar < 0)
            return;
        if(tar == 0) {
            res.push_back(combs);
            return;
        }
        for(int i = k; i < cands.size(); ++i) {
            combs.push_back(cands[i]);
            search(cands, i, tar - cands[i]);
            combs.pop_back();
        }
    }
};
