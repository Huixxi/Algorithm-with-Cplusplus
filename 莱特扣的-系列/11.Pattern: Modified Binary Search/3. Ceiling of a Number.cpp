class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int n = prices.size();
        double ceil_sum = 0.0, floor_sum = 0.0;
        vector<double> diffs;
        for(auto& str : prices) {
            double tmp = stod(str);
            ceil_sum += ceil(tmp);
            floor_sum += floor(tmp);
            diffs.push_back(tmp - floor(tmp));
        }
        if(ceil_sum < target || floor_sum > target)
            return "-1";
        sort(diffs.begin(), diffs.end());
        target = n + floor_sum - target;
        double res = 0.0;
        for(int i = 0; i < n; ++i) {
            if(i < target)
                res += diffs[i];
            else
                res += 1 - diffs[i];
        }    
        return to_string(res);
    }
};
