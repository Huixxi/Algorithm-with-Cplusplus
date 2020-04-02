class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        const int l = Profits.size();
        priority_queue<int, vector<int>, less<int>> maxheap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        for(int i = 0; i < l; ++i) {
            if(Profits[i] > 0) {
                if(Capital[i] <= W)
                    maxheap.push(Profits[i]);
                else
                    minheap.emplace(Capital[i], Profits[i]);
            }
        }
        while(k-- && !maxheap.empty()) {
            W += maxheap.top();
            maxheap.pop();
            while(!minheap.empty() && minheap.top().first <= W) {
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
        }
        return W;
    }
};
