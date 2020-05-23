class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k > input.size())
            return res;
        priority_queue<int, vector<int>, less<>> maxheap;
        for(auto& x : input) {
            maxheap.push(x);
            if(maxheap.size() > k)
                maxheap.pop();
        }
        while(!maxheap.empty()) {
            res.push_back(maxheap.top());
            maxheap.pop();
        }
        return res;
    }
};
