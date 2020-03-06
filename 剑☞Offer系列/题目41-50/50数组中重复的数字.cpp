class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 0)
            return false;
        *duplication = -1;
        vector<int> res(length, 0);
        for(int i = 0; i < length; ++i) {
            ++res[numbers[i]];
            if(numbers[i] >= length)
                return false;
            if(res[numbers[i]] == 2) {
                *duplication = numbers[i];
                return true;
            }
        }
        if(*duplication == -1)
            return false;
        return true;
    }
};
