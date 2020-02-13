class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        // 先排个序 O(nlogn)
        sort(data.begin(), data.end());
        int flag = 0;
        if(data[0] != data[1]) {
            *num1 = data[0];
            ++flag;
        }
        for(int i = 1; i < data.size() - 1; ++i) {
            if(data[i] != data[i-1] && data[i] != data[i+1]) {
                if(flag == 0) {
                    *num1 = data[i];
                    ++flag;
                }
                else if(flag == 1) {
                    *num2 = data[i];
                    ++flag;
                }
            }
            if(flag == 2)
                return;
        }
        *num2 = data[data.size() - 1];
    }
};
