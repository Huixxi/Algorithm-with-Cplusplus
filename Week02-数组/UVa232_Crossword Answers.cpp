#include <bits/stdc++.h>
using namespace std;

int main() {
    char puzzle[10][10];
    int idx[10][10] = {{0}, {0}};
    int r, c, Case=1, id;
    string s;
    while(cin >> r && r != 0) {
        if(Case != 1) cout << endl;
        cin >> c;
        id = 1;
        for(int i = 0; i < r; ++i) {
            cin >> s;
            for(int j = 0; j < c; ++j) {
                puzzle[i][j] = s[j];
                if(((i-1 < 0 || puzzle[i-1][j] == '*') || (j-1 < 0 || puzzle[i][j-1] == '*')) && puzzle[i][j] != '*') {
                    idx[i][j] = id;
                    ++id;
                }
            }
        }
        cout << "puzzle #" << Case << ":" << endl;
        cout << "Across";
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if((j-1 < 0 || puzzle[i][j-1] == '*') && puzzle[i][j] != '*')
                    cout << endl << setw(3) << idx[i][j] << '.';
                if(puzzle[i][j] != '*')
                    cout << puzzle[i][j];
            }
        }
        cout << endl << "Down" << endl;
        string ls[100] = {""}, temp = "";
        int temp_id = 0;

        for(int j = 0; j < c; ++j) {
            for(int i = 0; i < r; ++i) {
                if((i-1 < 0 || puzzle[i-1][j] == '*') && puzzle[i][j] != '*') {
                    ls[temp_id] = temp;
                    temp = "";
                    temp_id = idx[i][j];
                }
                if(puzzle[i][j] != '*')
                    temp += puzzle[i][j];
            }
        }
        ls[temp_id] = temp;
        for(int i = 0; i <= r*c; ++i) {
            if(ls[i] != "")
                cout << setw(3) << i << '.' << ls[i] << endl;
        }
        ++Case;
    }
    return 0;
}
