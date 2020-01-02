# 基础数论
### 斐波那契数（Fibonacci数）
$f(1) = 1, f(0) = 0.$   
$f(n) = f(n-1) + f(n+2)$   
**注：**`f(n)%n`是一个周期序列.

### 卡特兰数（Catlan数）
$C_0 = 1, C_{n+1} = \sum_{i=0}^n C_iC_{n-i}(n>=0)$  Or: $C(n) = \frac{2n(2n-1)}{(n+1)n}C(n-1)$

### 组合计数
$C_m^n = \frac{m!}{(m-n)!n!}$

**习题：**  
* **[**[UVa948:Fibonaccimal Base](https://vjudge.net/problem/UVA-948)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10689:Yet another Number Sequence](https://vjudge.net/problem/UVA-10689)**]** **[**[Solution(C++)]()**]**
* **[**[UVa991:Safe Salutations](https://vjudge.net/problem/UVA-991)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10007:Count the Trees](https://vjudge.net/problem/UVA-10007)**]** **[**[Solution(C++)]()**]**
