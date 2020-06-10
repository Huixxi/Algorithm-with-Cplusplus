## Bit-Manipulation(位操作)
From https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/

**1) How to check if a given number is a power of 2 ?**  
* Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.  
1 = (1) = 2^0; 2 = (10) = 2^1; 4 = (100) = 2^2; ...

* (x-1) will have all the bits same as x, except for the rightmost 1 in x and all the bits to the right of the rightmost 1.   
x = 4 = (100); x-1 = 3 = (011); ...  
x & (x-1) = 4 & 3 = (100) & (011) = (000)

```c++
bool isPowerOfTwo(int x) {
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}
```


**2) Count the number of ones in the binary representation of the given number.**  
```c++
int count = 0;
int count_one(int n) {
    while(n) {
        n = n & (n - 1);
        ++count;
    }
    return count;
}
```


**3) Check if the ith bit is set in the binary form of the given number.**  
```c++
bool check(int N) {
    return (N & (1 << i));
}
```


**4) :star:How to generate all the possible subsets of a set ?**  
Consider a set A of 3 elements.  
A = {a, b, c}   

0 = (000) = {}  
1 = (001) = {c}  
2 = (010) = {b}  
3 = (011) = {b, c}  
4 = (100) = {a}  
5 = (101) = {a, c}  
6 = (110) = {a, b}  
7 = (111) = {a, b, c}   

```c++
void possibleSubsets(char A[], int N) {
  for(int i = 0;i < (1 << N); ++i) {
      for(int j = 0; j < N; ++j)
          if(i & (1 << j))
              cout << A[j] << ‘ ‘;
      cout << endl;
  }
}
```


**5) Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.**  
**Idea:** Change all the bits which are at the right side of the most significant digit, to 1.  

**Property:** As we know that when all the bits of a number N are 1, then N must be equal to the `2^i - 1` , where i is the number of bits in N.   

```c++
long largest_power(long N) {
    //changing all right side bits to 1.
    N = N | (N>>1);
    N = N | (N>>2);
    N = N | (N>>4);
    N = N | (N>>8);

    //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by 2. 
    return (N+1)>>1;
}
```


**Tricks with Bits:**  
1) `x ^ ( x & (x-1))` : Returns the rightmost 1 in binary representation of x.   
2) `x & (-x)` : Returns the rightmost 1 in binary representation of x.  
3) `x | (1 << n)` : Returns the number x with the nth bit set. 
