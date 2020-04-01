class MedianFinder {
public:
    /** initialize your data structure here. */
    int cnt;
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        if(cnt % 2 == 0) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        ++cnt;
    }
    
    double findMedian() {
        if(cnt % 2 == 0)
            return (double)(maxheap.top() + minheap.top()) / 2; 
        else
            return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
