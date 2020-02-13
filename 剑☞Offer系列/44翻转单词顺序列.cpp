class Solution {
public:
    string ReverseSentence(string str) {
        stringstream ss;
        ss << str;
        string s, newstr;
        ss >> newstr;
        if(newstr.empty())  // 判断字符串是否全由空格组成
            return str;
        while(ss >> s)
            newstr = s + " " + newstr;
        return newstr;
    }
};
