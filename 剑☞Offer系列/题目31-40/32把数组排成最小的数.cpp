class Solution {
public:
    static bool comp(int a, int b) {
        string A = to_string(a);  // eg. 12
        string B = to_string(b);  // eg. 2
        return A + B < B + A;  // 122 < 212
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        if(numbers.empty())
            return res;
        sort(numbers.begin(), numbers.end(), comp);
        for(auto n : numbers)
            res += to_string(n);
        return res;
    }
};
