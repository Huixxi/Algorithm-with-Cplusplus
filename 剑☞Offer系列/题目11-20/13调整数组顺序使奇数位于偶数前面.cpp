class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        vector<int> a1, a2;
        for(int i = 0; i < len; ++i) {
            if(array[i] % 2 == 1) 
                a1.push_back(array[i]);
            else
                a2.push_back(array[i]);
        }
        for(int i = 0; i < len; ++i) {
            if(i < a1.size())
                array[i] = a1[i];
            else
                array[i] = a2[i - a1.size()];
        }
    }
};
