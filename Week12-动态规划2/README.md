# 动态规划进阶
可以用动态规划解决的问题包含两个性质：  
* 最优子结构（Optimal Substructure）
如果给定问题的最优解可以通过使用子问题的最优解来获得，这个给定的问题则具有最优子结构性质。
* 重叠子问题（Overlapping Subproblems）
类似分治法，动态规划也会组合子问题的解。不同是的，在动态规划中这些子问题的解会被重复利用，将被重复使用的子问题的解存在一个表中则避免了这些子问题解的重复计算，大大减少了计算时间。可以理解为，带记忆的递归。

## 01背包问题
Given weights(**w**) and values(**v**) of **n** items, put these items in a knapsack of capacity **W** to get the maximum total value in the knapsack.（给定**n**个物品的重量**w**和价值**v**，把它们放进一个容量为**W**的背包中，使获得价值最大。）  
E.g.:  
```python
# 3件物品，背包容量为50
values = [80, 100, 120]
weights = [10, 20, 30]
W = 50
```
**解释：**  
所谓0-1，就是拿或不拿，物品不可拆分。对于每个物品来说，都有两种情况，即在或不在最优子集中。因此，我们可以获得的最大价值，则为一下两种情况中的最大值：
* 


**习题：**  
* **[**[UVa10616:Divisible Group Sums](https://vjudge.net/problem/UVA-10616)**]** **[**[Solution(C++)]()**]**
* **[**[UVa11341:Term Strategy](https://vjudge.net/problem/UVA-11341)**]** **[**[Solution(C++)]()**]**
* **[**[UVa1213:Sum of Different Primes](https://vjudge.net/problem/UVA-1213)**]** **[**[Solution(C++)]()**]**


## 无穷背包问题

**习题：**  
* **[**[UVa357:Let Me Count The Ways](https://vjudge.net/problem/UVA-357)**]** **[**[Solution(C++)]()**]**
* **[**[UVa11137:Ingenuous Cubrency](https://vjudge.net/problem/UVA-11137)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10313:Pay the Price](https://vjudge.net/problem/UVA-10313)**]** **[**[Solution(C++)]()**]**
