#include <bits/stdc++.h> 
using namespace std; 

// A pair of pairs, first element is going to store 
// < value, <index of array, element index in the array> >. 
typedef pair<int, pair<int, int> > ppi; 

int mThLargest(vector<vector<int> > arr, int m) { 
    // Create a min heap with k heap nodes. Every 
    // heap node has first element of an array 
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq; 

    for (int i = 0; i < arr.size(); i++) 
        pq.push({ arr[i][0], { i, 0 } }); 

    // Now one by one get the minimum element 
    // from min heap and replace it with next 
    // element of its array 
    int count = 0; 
    int i = 0, j = 0; 
    while (count < m && pq.empty() == false) { 
        ppi curr = pq.top(); 
        pq.pop(); 

        // i ==> Array Number 
        // j ==> Index in the array number 
        i = curr.second.first; 
        j = curr.second.second; 

        // The next element belongs to same array as 
        // current. 
        if (j + 1 < arr[i].size()) 
            pq.push({ arr[i][j + 1], { i, j + 1 } }); 

        count++; 
    } 
    return arr[i][j]; 
} 

// Driver program to test above functions 
int main() { 
    vector<vector<int> > arr{ { 2, 6, 12 }, 
                              { 1, 9 }, 
                              { 23, 34, 90, 2000 } }; 

    int m = 4; 
    cout << mThLargest(arr, m); 

    return 0; 
} 
