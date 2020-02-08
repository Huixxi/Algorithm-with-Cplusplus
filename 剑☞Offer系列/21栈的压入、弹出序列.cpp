class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        // 绝对顺序保持不变（方法一）
        // auto l = pushV.begin();
        // for(auto i = popV.begin(); i < popV.end(); ++i) {
        //     auto it = find(pushV.begin(), pushV.end(), *i);
        //     if(it == pushV.end())
        //         return false;
        //     if(it > l) {
        //         auto temp = i;
        //         for(auto j = it - 1; j >= l; --j) {
        //             auto x = find(i, popV.end(), *j);
        //             if(x < temp)
        //                 return false;
        //             temp = x;
        //         }
        //         l = it + 1;
        //     }
        // }
        // return true;
        
        // 模拟一遍（方法2）
        stack<int> stk;
        int j = 0;
        for(auto& i : pushV) {
            stk.push(i);
            while(!stk.empty()) {
                if(stk.top() != popV[j])
                    break;
                stk.pop();
                ++j;
            }
        }
        return j == pushV.size();
    }
};
