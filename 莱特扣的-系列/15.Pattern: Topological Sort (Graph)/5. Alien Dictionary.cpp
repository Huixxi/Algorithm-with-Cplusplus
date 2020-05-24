class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        string res;
        int cnt = 0;
        vector<int> labels(26, 0);
        vector<int> inDegree(26, 0);
        vector<int> exist(26, 0);
        vector<vector<int>> adjList(26, vector<int>());
        
        for(auto& w : words) 
            for(auto& c : w) 
                exist[c - 'a'] = 1;
        
        for (int i = 0; i < (int)words.size() - 1; ++i) { 
            // Take the current two words and find the first mismatching character 
            string word1 = words[i], word2 = words[i+1]; 
            for (int j = 0; j < (int)min(word1.length(), word2.length()); j++) { 
                // If we find a mismatching character, then add an edge 
                // from character of word1 to that of word2 
                if (word1[j] != word2[j]) { 
                    labels[word1[j] -'a'] = 1;
                    labels[word2[j] -'a'] = 1;
                    adjList[word1[j] -'a'].push_back(word2[j] -'a'); 
                    ++inDegree[word2[j] -'a'];
                    ++cnt;
                    break; 
                } 
            } 
        }
        
        queue<int> q;
        for(int i = 0; i < 26; ++i) {
            if(inDegree[i] == 0 && labels[i] == 1)
                q.push(i);
        }
        while(!q.empty()) {
            int cur = q.front();
            res += char(cur + 'a');
            q.pop();
            --cnt;
            for(auto v : adjList[cur]) {
                if(--inDegree[v] == 0)
                    q.push(v);
            }
        }
        string tmp;
        int idx = 0;
        for(int i = 0; i < 26; ++i) {
            if(exist[i] == 1 && labels[i] == 0) {
                if(i + 'a' < res[idx])
                    tmp += char(i + 'a');
                else {
                    while(idx < res.length() && i + 'a' > res[idx]) {
                        tmp += res[idx];
                        ++idx;
                    }
                    tmp += char(i + 'a');
                }
            }
        }
        while(idx < res.length()) {
            tmp += res[idx];
            ++idx;
        }
        // cout << cnt;
        return cnt == -1 ? tmp : "";
    }
};
