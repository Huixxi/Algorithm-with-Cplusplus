/*
  使用栈(stack)来解决此题，否则会很难想。。。
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> mm = {{')', '('}, {']', '['}, {'}', '{'}};
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {
                if(!stk.empty() && mm[c] == stk.top()) 
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
