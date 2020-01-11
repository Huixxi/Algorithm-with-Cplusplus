#include <bits/stdc++.h>
#define int long long   //注意 这是偷懒写法 为什么需要long long主要是因为 素数筛里面有i*i会爆int
using namespace std;
bool is_prime_naive(int n) {//O(n)找出所有质数
    for(int i = 2;i <= n-1; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
bool is_prime_sqrtn(int n) { //O(sqrt(n))找出所有质数
    for(int i = 2;i <= sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
const int sieve_size = 1e6;   //筛的范围
vector<int> primes;     //存质数
vector<int> flag(sieve_size + 10, 0);
void sieve() {   //素数筛板子 O(nlog(n)) 找出所有小于等于sieve_size的质数
    for(int i = 2;i <= sieve_size; i++){
        if(!flag[i]){
            primes.push_back(i);
            for(int j = i*i; j <= sieve_size; j+=i){
                flag[j] = 1;
            }
        }
    }
}
bool is_prime_advance(int n){   //比O(sqrt(n))更快一点的质数判断
    if(n <= sieve_size)
        return !flag[n];
    for(int i = 0; i < (int)primes.size(); i++){
        if(n%primes[i] == 0)
            return false;
    }
    return true;
}
vector<int> prime_factor;
void prime_fac(int n){  //非常快 出题人卡不住的快
    int poi = 0;
    while(primes[poi] <= sqrt(n)){
        while(n%primes[poi] == 0){
            n /= primes[poi];
            prime_factor.push_back(primes[poi]);
        }
            poi++;
    }
    if(n != 1)
        prime_factor.push_back(n);
}
int32_t main(){
    int n;
    cin>>n;
    sieve();    

    // cout << is_prime_naive(n) << endl;
    // cout << is_prime_sqrt(n) << endl;
    cout << is_prime_advance(n) << endl;
    prime_fac(142391208960ll);
    for(auto it : prime_factor)
        cout << it << " ";
    cout << endl;
    return 0;
}
