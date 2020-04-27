/*
Create a hash table to store the frequency of each element.
Insert frequency of each element in a max heap.
Now, perform the following operation k times. Remove an element from the max heap. Decrement its value by 1. 
After this if element is not equal to 0, then again push the element in the max heap.
After the completion of step 3, the number of elements in the max heap is the required answer.
*/
// C++ implementation to find maximum distinct 
// elements after removing k elements 
#include <bits/stdc++.h> 
using namespace std; 

// function to find maximum distinct elements after removing k elements 
int maxDistinctNum(int arr[], int n, int k) { 
    // 'um' implemented as hash table to store frequency of each element 
    unordered_map<int, int> um; 

    // priority_queue 'pq' implemented as 
    // max heap 
    priority_queue<int> pq; 

    // storing frequency of each element in 'um' 
    for (int i = 0; i < n; i++) 
        um[arr[i]]++; 

    // inserting frequency of each element in 'pq' 
    for (auto it = um.begin(); it != um.end(); it++) 
        pq.push(it->second); 

    while (k--) { 
        // get the top element of 'pq' 
        int temp = pq.top(); 

        // remove top element from 'pq' 
        pq.pop(); 

        // decrement the popped element by 1 
        temp--; 

        // if true, then push the element in 'pq' 
        if (temp != 0) 
          pq.push(temp); 
    } 

    // Count all those elements that appear 
    // once after above operations. 
    int res = 0; 
    while (pq.empty() == false) { 
      int x = pq.top(); 
      pq.pop(); 
      if (x == 1) 
      res++; 
    }	 
    return res; 
} 

// Driver program to test above 
int main() { 
    int arr[] = { 5, 7, 5, 5, 1, 2, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << "Maximum distinct elements = " << maxDistinctNum(arr, n, k); 
	  return 0; 
} 
