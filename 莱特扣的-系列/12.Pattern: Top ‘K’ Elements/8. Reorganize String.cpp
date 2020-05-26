class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> mm;
        for(auto& c : S)
            ++mm[c];
        priority_queue< pair<int, char>, vector<pair<int, char>>, less<> > pq;
        for(auto& m : mm)
            pq.push(make_pair(m.second, m.first));
        
        string res;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            while(t.first > 0 && !pq.empty()) {
                res += t.second;
                auto p = pq.top();
                pq.pop();
                res += p.second;
                --p.first;
                if(p.first != 0)
                    pq.push(p);
                --t.first;
            }
            if(t.first > 0) {
                if (t.first >= 2 || t.second == res.back())
                    return "";
                else
                    res += t.second;
            }
        }
        return res;
    }
};
