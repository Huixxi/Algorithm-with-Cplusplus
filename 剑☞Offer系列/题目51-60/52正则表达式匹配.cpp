class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern + 1) == '*') {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern) || match(str, pattern + 2);
            else
                return match(str, pattern + 2);
        }
        else {
            if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
    }
};
