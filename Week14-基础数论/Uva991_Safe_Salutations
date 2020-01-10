// A easy one, just use "Catalan Equation", but can get "Presentation error"输出格式错误, be careful.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, Case=0;
    while(cin >> n) {
        int c = 1;
        for(int i = 0; i < n; ++i) {
            c = (2 * (2*i+1) * c) / (i+2);  // be careful, think why not c *= 2*(2*i+1)/(i+2);
        }
        if(Case++)
            cout << endl;
        cout << c << endl;
    }
    return 0;
}
