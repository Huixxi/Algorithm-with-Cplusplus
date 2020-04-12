class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk; 
        string res;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(')
                stk.push(i);
            if(s[i] == ')') {
                if(!stk.empty())
                    stk.pop();
                else
                    s[i] = '*';
            }
        }
        while(!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }
        for(auto& c : s) {
            if(c != '*')
                res += c;
        }
        return res;
    }
};
