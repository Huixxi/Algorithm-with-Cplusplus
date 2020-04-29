class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxSW;
        deque<int> dq;
        for(int i = 0; i < nums.size(); ++i) {
            while(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                maxSW.push_back(nums[dq.front()]);
        }
        return maxSW;
    }
};
