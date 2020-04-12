class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        int n = word.length();
        int maxN = 1 << n;
        vector<string> res;
        res.reserve(maxN);
        for(int i = 0; i < maxN; ++i) {
            string tmps;
            int t = 0;
            for(int j = 0; j < n; ++j) {
                if((i >> j) & 1 == 1)
                    ++t;
                else {
                    if(t != 0) {
                        tmps += to_string(t);
                        t = 0;
                    }
                    tmps += word[j];
                }
            }
            if(t != 0)
                tmps += to_string(t);
            res.push_back(tmps);
        }
        return res;
    }
};
