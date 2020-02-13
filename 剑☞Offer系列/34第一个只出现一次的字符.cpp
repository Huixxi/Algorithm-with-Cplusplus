class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mm;
        for(auto& c : str) {
            if(mm.find(c) != mm.end())
                ++mm[c];
            else
                mm[c] = 1;
        }
        for(int i = 0; i < str.length(); ++i) {
            if(mm[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
