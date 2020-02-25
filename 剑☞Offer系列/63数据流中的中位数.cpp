class Solution {
public:
    // 最大堆和最小堆（通常为完全二叉树，故用数组存储）
    void Insert(int num)
    {
        if(count % 2 == 0) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        ++count;
    }

    double GetMedian()
    {
        if(count % 2 == 1)
            return (double)minheap.top();
        else
            return (double)(minheap.top() + maxheap.top()) / 2;
    }
private:
    int count = 0;
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
};
