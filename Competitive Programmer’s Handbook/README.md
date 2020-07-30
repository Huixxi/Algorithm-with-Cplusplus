## Code and Solution in "[Competitive Programmer’s Handbook](https://cses.fi/book/book.pdf)"

### I Basic Techniques

#### Time Complexity
* `n <= 10` : `O(n!)`
* `n <= 20` : `O(2^n)`
* `n <= 500` : `O(n^3)`
* `n <= 5000` : `O(n^2)`
* `n <= 10^6` : `O(nlogn)` or `O(n)`
* `n is large` : `O(1)` or `O(logn)`

#### Sorting
Two ways to compare the user-defined structs:   
```c++
struct P {
    int x, y;
    bool operator< (const P &p) {
        if (x != p.x) 
            return x < p.x;
        return y < p.y;
    }
}
```
```c++
// sort strings primarily by length and secondarily by alphabetical order
static bool comp(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
sort(v.begin(), v.end(), comp);
```

#### Binary search
Method1:
```c++
int a = 0, b = n - 1;
while(a <= b) {
    int mid = a + (b - a) / 2;
    if(array[mid] == x)
        // find x at mid
    if(array[mid] > x)
        b = mid - 1;
    else 
        a = mid + 1;
}
```
Method2: a more efficient way
```c++
int k = 0;
// b: jump steps
for(int b = n / 2; b >= 1; b /= 2) {
    while(k + b < n && array[k + b] <= x)
        k += b;
}
if(array[k] == x) {
    // x found at index k
}
```
*Find the smallest number that satisfy a give function ok(x)*
```c++
int x = -1;
// z: a large enough number that ok(z) is true
while(int b = z; b >= 1; b /= 2) {
    while(!ok(x + b))
        x += b;
}
int k = x + 1;
```
*Find the maximum number the peek number in a first increasing then decreasing array*
```c++
int x = -1;
// z: a large enough number that ok(z) is true
while(int b = z; b >= 1; b /= 2) {
    while(f(x + b) < f(x + b + 1))
        x += b;
}
int k = x + 1;
```


### II Graph Algorithms


### III Advanced Topics
