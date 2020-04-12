/*
Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC
*/

vector<string> letterCasePermutation(string S) {
    vector<string> res;
    int n = S.length();
    int maxn = 1 << n;
    transform(S.begin(), S.end(), S.begin(), ::tolower); 
    for(int i = 0; i < maxn; ++i) {
        string tmp = S;
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1)
                tmp[j] = toupper(S[j]);
        }
        res.push_back(tmp);
    }
    return res;
}
