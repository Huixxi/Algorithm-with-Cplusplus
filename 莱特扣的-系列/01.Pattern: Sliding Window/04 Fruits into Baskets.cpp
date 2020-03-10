class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // Just the longest substring with at most two distinct characters
        int i = 0, j = 0, l = 0;
        unordered_map<int, int> mm;
        while(j < tree.size()) {
            if(mm.find(tree[j]) != mm.end())
                ++mm[tree[j]];
            else
                mm[tree[j]] = 1;
            l = max(l, j - i);
            while(mm.size() > 2) {
                if(mm[tree[i]] > 1)
                    --mm[tree[i]];
                else
                    mm.erase(tree[i]);
                ++i;
            }
            ++j;
        }
        return max(l, j - i);
    }
};
