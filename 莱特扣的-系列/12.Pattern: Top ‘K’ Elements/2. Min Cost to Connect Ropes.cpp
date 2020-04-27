class Solution {
public:
    int minCost(vector<int>& ropes) {
        int tolCost = 0;  
        priority_queue<int, vector<int>, greater<>> pq;  // min-heap
        for(auto& rope : ropes)
            pq.push(rope);
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            tolCost += a + b;
            pq.push(a + b);
        }
        return tolCost;
    }
};
