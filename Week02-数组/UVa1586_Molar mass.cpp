#include <bits/stdc++.h>
using namespace std;

map<char, float> atom_mass = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string molecule;
    while(n--) {
        getline(cin, molecule);
        stringstream ss;
        ss << molecule;

        char atom;
        int num;
        float sum = 0.0;

        while(!ss.eof()) {
            ss >> atom;
            if(ss.eof())
                break;
            if(!(ss >> num)) {
                sum += atom_mass[atom];
                ss.clear();
            }
            else {
                sum += num * atom_mass[atom];
            }
        }
        cout << setprecision(3) << fixed;
        cout << sum << endl;
    }
    return 0;
}
