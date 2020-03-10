#include <iostream>
using namespace std;

int findLen(string& s, int k, char c) {
    int i = 0, j = 0, l = 0, cnt = 0;
    while(j < s.length()) {
        if(s[j] != c)
            ++cnt;
        while(cnt > k) {
            if(s[i] != c)
                --cnt;
            ++i;
        }
        l = max(l, j - i + 1);
        ++j;
    }
    return l;
}

int main() {
	int maxlen;
	int t, n, k;
	string s;
	cin >> t;
	while(t > 0) {
	    maxlen = 0;
	    cin >> n >> k;
	    cin >> s;
	    for(int i = 0; i < 26; ++i) {
	        maxlen = max(maxlen, findLen(s, k, 'A' + i));
	        maxlen = max(maxlen, findLen(s, k, 'a' + i));
	    }
	    cout << maxlen << endl;
	    --t;
	}
	return 0;
}
