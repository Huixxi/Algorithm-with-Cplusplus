class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int cnt = 0;
        multiset<int, greater<int>> maxheap;
        multiset<int, less<int>> minheap;
        if(k == 1)
            return vector<double>(nums.begin(), nums.end());
        while(cnt < k && cnt < nums.size()) {
            if(cnt % 2 == 0) {
                maxheap.insert(nums[cnt]);
                minheap.insert(*maxheap.begin());
                maxheap.erase(maxheap.begin());
            }
            else {
                minheap.insert(nums[cnt]);
                maxheap.insert(*minheap.begin());
                minheap.erase(minheap.begin());
            }
            ++cnt;
        }
        if(cnt % 2 == 0)
            res.push_back(double(*maxheap.begin()) / 2 + double(*minheap.begin()) / 2);
        else
            res.push_back(double(*minheap.begin()));
        while(cnt < nums.size()) {
            if(nums[cnt - k] > *maxheap.begin()) {
                minheap.erase(minheap.find(nums[cnt - k]));
                if(nums[cnt] > *maxheap.begin())
                    minheap.insert(nums[cnt]);
                else {
                    minheap.insert(*maxheap.begin());
                    maxheap.erase(maxheap.begin());
                    maxheap.insert(nums[cnt]);
                }
            }
            else {
                maxheap.erase(maxheap.find(nums[cnt - k]));
                if(nums[cnt] >= *minheap.begin()) {
                    maxheap.insert(*minheap.begin());
                    minheap.erase(minheap.begin());
                    minheap.insert(nums[cnt]);
                }
                else 
                    maxheap.insert(nums[cnt]);
            }
            if(k % 2 == 0)
                res.push_back(double(*maxheap.begin()) / 2 + double(*minheap.begin()) / 2);
            else
                res.push_back(double(*minheap.begin()));
            ++cnt;
        }
        return res;
    }
};
