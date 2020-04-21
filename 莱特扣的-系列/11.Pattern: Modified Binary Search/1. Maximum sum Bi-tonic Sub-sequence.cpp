#include <bits/stdc++.h>
using namespace std;

int maxSumBitonicSubArr(int arr[], int n) {
    int msis[n], msds[n];
    msis[0] = arr[0];
    msds[n-1] = arr[n-1];
    for(int i = 1; i < n; ++i) {
        if(arr[i] > arr[i-1])
            msis[i] = msis[i-1] + arr[i];
        else
            msis[i] = arr[i];
    }
    for(int i = n-2; i >= 0; --i) {
        if(arr[i] > arr[i+1]
            msds[i] = msds[i+1] + arr[i];
        else 
            msds[i] = arr[i];
    }
    for (int i = 0; i < n; ++i)
        max_sum = max(max_sum, msis[i] + msds[i] - arr[i]); 
      
    return max_sum;
}
