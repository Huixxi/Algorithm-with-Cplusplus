class Solution {
public:
  左旋转字符串  string LeftRotateString(string str, int n) {
        for(int i = 0; i < n; ++i) {
            str += str[i];
        }
        return str.substr(n, str.length());
    }
};
