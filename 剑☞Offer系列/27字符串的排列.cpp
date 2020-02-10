class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.length() == 0)
            return res;
        Permu(str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void Permu(string& str, int begin) {
        if(begin == str.length() - 1)
            res.push_back(str);
        else {
            for(int p = begin; p < str.length(); ++p) {
                if(p != begin && str[p] == str[begin])
                    continue;
                // swap
                char t = str[begin];
                str[begin] = str[p];
                str[p] = t;
                Permu(str, begin + 1);
                // swap back
                t = str[begin];
                str[begin] = str[p];
                str[p] = t;
            }
        }
    }
private:
    vector<string> res;
};
