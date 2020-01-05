# 基础数论
### 斐波那契数（Fibonacci数）
$f(1) = 1, f(0) = 0.$   
$f(n) = f(n-1) + f(n+2)$   
**Note:** **`f(n)%n`** is a periodic sequence.  
  
**To Find The Index Of A Given Fibonacci Number:**  
```c++
// Formula based Method: 
// Fibs = [0, 1, 1, 2, 3, 5, 8, 13, ...]
// n = round { 2.078087 * log(Fn) + 1.672276 }
#include<bits/stdc++.h> 
  
int findIndex(int Fn) 
{ 
    float fibo = 2.078087 * log(Fn) + 1.672276; 
    return round(fibo); 
} 

int main() 
{ 
    int Fn = 55; 
    cout << findIndex(Fn); 
} 

// Output: 10
```

### 卡特兰数（Catalan数）
$C_0 = 1, C_{n+1} = \sum_{i=0}^n C_iC_{n-i}(n>=0)$  **Or:**  $C(n) = \frac{2n(2n-1)}{(n+1)n}C(n-1)$

### 组合计数
$C_m^n = \frac{m!}{(m-n)!n!}$

**板子：**  
```c++
#include <bits/stdc++.h>
#define int long long

using namespace std;


```

**习题：**  
* **[**[UVa948:Fibonaccimal Base](https://vjudge.net/problem/UVA-948)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa10689:Yet another Number Sequence](https://vjudge.net/problem/UVA-10689)**]** **[**[Solution(C++)][2]**]**
* **[**[UVa991:Safe Salutations](https://vjudge.net/problem/UVA-991)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10007:Count the Trees](https://vjudge.net/problem/UVA-10007)**]** **[**[Solution(C++)]()**]**

[1]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/UVA948_Fibonaccimal_Base.cpp
[2]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week14-%E5%9F%BA%E7%A1%80%E6%95%B0%E8%AE%BA/Uva10689_Yet_another_Number_Sequence.cpp

