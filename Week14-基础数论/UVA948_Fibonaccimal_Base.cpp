#include <iostream>
#include <vector>
#include <string>

using namespace std;

// find the nearest fib num
int find_fib_leq_n(int n, vector<int>& ids, int* id) {
    int f0 = 0, f1 = 1;
    int f;
    while(true) {
        f = f0 + f1;
        if(n < f)
            break;
        f0 = f1;
        f1 = f;
        ++(*id);
    }
    ids.push_back(*id);
    return f1;
}

void Fibonaccimal_Base_Uva948(int n, vector<int>& ids, int id = 0) {
    int f = find_fib_leq_n(n, ids, &id);
    if(n == f)
        return;
    Fibonaccimal_Base_Uva948(n-f, ids);
}

int main() {
    int N;
    cin >> N;
    for(int x = 0; x < N; ++x) {
        int n;
        cin >> n;
        /* -----start----- */
        vector<int> ids;  // to save ids where should be 1
        Fibonaccimal_Base_Uva948(n, ids);

        int fbits[ids[0]];
        for(auto& i : fbits) {
            i = 0;  // initialize each element to 0
        }
        for(auto i : ids) {
            fbits[ids[0]-i] = 1;
        }
        /* -----output----- */
        cout << n << " = ";
        for(auto i : fbits)
            cout << i;
        cout << " (fib)" << endl;
    }
    return 0;
}
