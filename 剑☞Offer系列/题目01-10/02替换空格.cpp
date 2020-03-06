class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == nullptr || length <= 0)
            return;
        int blanknum = 0, origlength = 0;
        for(int i = 0; str[i] != '\0'; ++i){
            ++origlength;
            if(str[i] == ' ')
                ++blanknum;
        }
        int newlength = origlength + 2 * blanknum;
        for(int j = origlength; j >= 0 && j < newlength; --j){
            if(str[j] != ' ')
                str[newlength--] = str[j];
            else{
                str[newlength--] = '0';
                str[newlength--] = '2';
                str[newlength--] = '%';
            }
        }
    }
};
