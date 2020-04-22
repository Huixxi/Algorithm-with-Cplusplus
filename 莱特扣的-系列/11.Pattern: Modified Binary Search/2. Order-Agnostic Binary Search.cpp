#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key) {
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0, end = n - 1;
    bool isAscending = arr[n-1] > arr[0];
    while(start <= end) {
        // the safest way to find the middle of two numbers without getting an overflow
        int mid = start + (end - start) / 2;  
        
        if(arr[mid] == key)
            return mid;
            
        if(isAscending) {
            if(key > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else {
            if(key < arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
