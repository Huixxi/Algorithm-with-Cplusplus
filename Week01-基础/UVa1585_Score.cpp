#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string oxstr;
    while(n--) {
        getline(cin, oxstr);
        int total_score = 0, score = 0;
        for(char c : oxstr) {
            if(tolower(c) == 'o'){
                score += 1;
                total_score += score;
            }
            else {
                score = 0;
            }
        }
        cout << total_score << endl;
    }
    return 0;
}
