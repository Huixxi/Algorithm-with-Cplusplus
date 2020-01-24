#include <bits/stdc++.h>
using namespace std;

map<string, int> mm;

int dfs(string& s) {
    if(s == "") 
        return 1;
    if(s.length() == 1)
        return 0;
    auto it = mm.find(s);
    if(it != mm.end())
        return it->second;
    string sub;
    int i, j;
    int& res = mm[s];
    for(i = 0; i < s.length(); ++i) {
        for(j = i; j < s.length(); ++j) {
            if(s[i] != s[j])
                break;
        }
        if(j >= i + 2) {
            sub = s.substr(0, i) + s.substr(j);
            res |= dfs(sub);
            if(res)
              return res;
            i = j - 1;
        }
    }
    return res;
}

int main() {
	  int n;
	  cin >> n;
	  string s;
	  while(n--) {
		    cin >> s;
		    cout << dfs(s) << endl;
	  }
	  return 0;
}
