class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        if(rotateArray.size() == 1)
            return rotateArray[0];
        for(int i = 1; i < rotateArray.size(); ++i)
            if(rotateArray[i] < rotateArray[i-1])
                return rotateArray[i];
    }
};
