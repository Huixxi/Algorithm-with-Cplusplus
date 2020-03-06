class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return dfs(sequence, 0, sequence.size() - 1);
    }
private:
    bool dfs(vector<int> v, int start, int end) {
        if(start >= end)  // if empty
            return true;
        int i;
        for(i = start; i < end; ++i) {
            if(v[i] > v[end])
                break;
        }
        for(int j = i; j < end; ++j)
            if(v[j] < v[end])
                return false;
        return dfs(v, start, i - 1) && dfs(v, i, end - 1);
    }
};
