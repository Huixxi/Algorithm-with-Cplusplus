class Solution {
public:
    // 为栈的每个状态都保存一个min值
    void push(int value) {
        data.push(value);
        if(dmin.empty())
            dmin.push(value);
        else {
            if(value > dmin.top())
                dmin.push(dmin.top());
            else
                dmin.push(value);
        }
    }
    void pop() {
        data.pop();
        dmin.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return dmin.top();
    }
private:
    stack<int> data;
    stack<int> dmin;
};
