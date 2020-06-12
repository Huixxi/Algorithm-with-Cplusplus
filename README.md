# Learning Algorithm with Yu in C++.
Bro Yu's Private Home Algorithm Cuisine.

### A typical C++ code template: 
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);  // to speed up `cin` `cout`.
    cin.tie(0);
    /* ... */
}
```

### Using the following command to compile the code:
```shell
g++ -std=c++11 -O2 -Wall test.cpp -o test
```   
then, `./test` to run your code.(explain: `-O2` optimizes the code, `-Wall` shows warnings about possible errors)   

### Some tricks used in programming:  
* the newline `"\n"` works faster than `endl`, because `endl` always causes a flush operation.

### Input and Output
In most contests, standard streams are used for reading input and writing output.   
```c++
int a, b;
string x;
cin >> a >> b >> x;
```
```c++
int a = 123, b = 456;
string x = "input";
cout << a << b << x << "\n";
```
Besides `cin`、`cout`, we can also use `scanf` for input, `printf` for output.  
```c
int a, b;
scanf("%d %d", &a, &b);
```
```c
int a = 123, b = 456;
printf("%d %d\n", a, b);
```
For string containing spaces, we use `getline`:
```c++
string x;
getline(cin, x);
```
For the amount of data is unknown, the following loop is useful:
```c++
// loop reads elements from the input until there is no more data available.
while(cin >> x) {
    /* ... */
}
```
In some contest systems, files are used for input and output:
```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

### Working with numbers
**Integers**(`long long` is usually enough)   
* `int`: `-2^31...2^31 - 1` or about `-2*10^9...2*10^9`
* `long long`: `-2^63...2^63 - 1` or about `-9*10^18...9*10^18`
* `__int128_t`: `-2^127...2^127 - 1` or about `-10^38...10^38`(may not available for all contest systems)

**Modular arithmetic**
```
(a + b) mod m = (a mod m + b mod m) mod m
(a − b) mod m = (a mod m − b mod m) mod m
(a · b) mod m = (a mod m · b mod m) mod m
```
make sure there are no negative remainders:
```
if (x < 0) x += m;
```

**Floating point numbers**  
The usual floating point types in competitive programming are the 64-bit `double` and, as an extension in the g++ compiler, the 80-bit `long double`. In most cases, `double` is enough, but `long double` is more accurate.   

An easy way to output the answer that required precision is to use the `printf` function and give the number of decimal places in the formatting string.
```c++
printf("%.9f\n", x);
```
Compare two float point number(to eliminate the round error):
```c++
if(abs(a - b) < 1e-9) {
    /* a and b are equal */
}
```

### Shortening code
**Type names**  
```c++
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
```

**Macros**  
```c++
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for(int i = a; i < b; ++i)
#define SQ(a) (a)*(a)

// now
for(int i = 1; i < n; ++i) {
    search(i);
}
// become 
REP(i, 1, n) {
    search(i);
}
```


### Recommended books for coding competition & tech-interview
1. [Competitive Programmer’s Handbook(Free PDF)](https://cses.fi/book/book.pdf) :star:
2. [Cracking the Coding Interview 6th Edition: 189 Programming Questions and Solutions](http://ahmed-badawy.com/blog/wp-content/uploads/2018/10/Cracking-the-Coding-Interview-6th-Edition-189-Programming-Questions-and-Solutions.pdf)
