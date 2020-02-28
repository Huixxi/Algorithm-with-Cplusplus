class Solution {
public:
    bool isNumeric(char* string)
    {
        // 垃圾题，操！
        int flag = 0, nep = 0, eflag = 0, pflag = 0;
        if(string[flag] == '+' || string[flag] == '-')
            ++flag;
        if(string[flag] < '0' || string[flag] > '9') {
            if(string[flag] == '.')
                ++pflag;
            else
                return false;
        }
        ++flag;
        for(int i = flag; string[i] != '\0'; ++i) {
            if((string[i] != 'e' && string[i] != 'E' && string[i] != '.') && (string[i] < '0' || string[i] > '9'))
                return false;
            if(string[i] == 'e' || string[i] == 'E') {
                if(string[i + 1] == '\0')
                    return false;
                if(string[i + 1] == '+' || string[i + 1] == '-')
                    ++i;
                ++eflag;
                ++nep;
            }
            else if(string[i] == '.') {
                if(eflag || (string[i + 1] < '0' || string[i + 1] > '9'))
                    return false;
                ++pflag;
                ++nep;
            }
            if(eflag > 1 || pflag > 1 || nep > 2)
                return false;
        }
        return true;
    }
};
