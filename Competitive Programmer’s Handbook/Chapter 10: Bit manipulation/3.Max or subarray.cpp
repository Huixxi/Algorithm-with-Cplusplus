/*
Input:
4
2 6 1 12
// The shortest subarray is [6, 1, 12][6,1,12] having the or value 15

4
1 2 4 8
// In order to have the maximum or value, we need to take all 4 elements.

5
5 3 6 5 6

Output:
3
4
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> elements(n);
    int or_sum = 0;
    for (int i = 0; i < n; i += 1) {
        cin >> elements[i];
        or_sum |= elements[i];
    }

    vector<int> last_seen(32, -1);
    int answer = n; // the min length of a segment that has the OR sum equal to the global one (or_sum)
    for (int i = 0; i < n; i += 1) {
        // add current element
        for (int j = 0; j < 30; j += 1) {
            if (elements[i] & (1 << j)) {
                last_seen[j] = i;
            }
        }

        // get min last_seen that is != 1 and compute current OR sum
        int mn_last_seen = i; // all elements will be <= i for sure
        int current_or = 0;
        for (int j = 0; j < 30; j += 1) {
            if (last_seen[j] != -1) {
                mn_last_seen = min(mn_last_seen, last_seen[j]);
                current_or |= (1 << j);
            }
        }

        if (current_or == or_sum) {
            answer = min(answer, i - mn_last_seen + 1);
        }
    }

    cout << answer << '\n';
    return 0;
}
