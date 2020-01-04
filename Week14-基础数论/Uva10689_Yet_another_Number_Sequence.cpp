// Almost totally copy from:
// https://github.com/morris821028/UVa/blob/master/volume106/10689%20-%20Yet%20another%20Number%20Sequence.cpp
// You should use Matrix Exponentiation(矩阵快速幂方法) which is a O(logn) complexity instead of O(n).
/*
// Recursion
int BinaryExp(long long x, int n) {
    if(n == 1) 
        return x;
    long long v = BinaryExp(x, n/2);
    if(n % 2)  
        return v * v * x;
    else 
        return v * v; 
}

// Non-Recursion
int BinaryExp(long long x, int n) {
    long long res = 1;
    while(n > 0) {
        if(n & 1) 
            res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}
*/

#include <bits/stdc++.h>
using namespace std;

struct Mat {
    int v[2][2];
} F = {1,1,1,0}, I = {1,0,0,1}, O = {0,0,0,0};

void matmul(Mat& Fmat, Mat& Bmat, int m) {
    static int i, j, k;
    Mat Tmat = O;
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            for(k = 0; k < 2; ++k) {
                Tmat.v[i][j] += Fmat.v[i][k] * Bmat.v[k][j];
                Tmat.v[i][j] %= m;
            }
        }
    }
    Fmat = Tmat;
}

Mat power(int n, int m) {
    Mat Fmat = F, Xmat = I;
    while(n) {
        if(n&1)  // n&1 == n%2, x>>1 == x/2
            matmul(Xmat, Fmat, m);
        matmul(Fmat, Fmat, m);
        n /= 2;
    }
    return Xmat;
}

int main() {
    int N;
    cin >> N;
    while(N--) {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        m = (int)pow(10, m);
        Mat res = power(n, m);
        int ans = res.v[1][0]*b + res.v[1][1]*a;
        cout << ans%m << endl;
    }
    return 0;
}
