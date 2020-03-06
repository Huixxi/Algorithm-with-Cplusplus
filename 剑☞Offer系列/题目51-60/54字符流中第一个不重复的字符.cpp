class Solution
{
public:
    // Insert one char from stringstream
    void Insert(char ch)
    {
        str += ch;
        ++count[ch];
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto c : str)
            if(count[c] == 1)
                return c;
        return '#';
    }
private:
    string str = "";
    char count[256] = {0};
};
