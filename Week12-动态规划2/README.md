# 动态规划进阶
可以用动态规划解决的问题包含两个性质：  
* 最优子结构（Optimal Substructure）  
如果给定问题的最优解可以通过使用子问题的最优解来获得，这个给定的问题则具有最优子结构性质。
* 重叠子问题（Overlapping Subproblems）  
类似分治法，动态规划也会组合子问题的解。不同是的，在动态规划中这些子问题的解会被重复利用，将被重复使用的子问题的解存在一个表中则避免了这些子问题解的重复计算，大大减少了计算时间。可以理解为，带记忆的递归。

**资料推荐：**  
* [背包问题九讲(Tianyi Cui)](https://raw.githubusercontent.com/tianyicui/pack/master/V2.pdf)

## 01背包问题
Given weights(**w**) and values(**v**) of **n** items, put these items in a knapsack of capacity **W** to get the maximum total value in the knapsack.（给定**n**个物品的重量**w**和价值**v**，把它们放进一个容量为**W**的背包中，使获得价值最大。）   
```python
# e.g. 3件物品，背包容量为50
values = [80, 100, 120]
weights = [10, 20, 30]
W = 50

# 输出：
220
```
**解释（自底向上法）：**  
所谓0-1，就是拿或不拿，物品不可拆分。对于每个物品来说，都有两种情况，即在或不在最优子集中。因此，从n件物品中我们可以获得的最大价值，则为以下两种情况中的最大值：  
* 不包含第n件物品，由之前的n-1件物品获得的最大价值和W容量，`d[n-1][W]`
* 包含第n件物品，加上由之前n-1件物品所获得的最大价值和W-w_n容量，`d[n-1][W-w_n] + v_n`  

即：`d[n][W] = max(d[n-1][W], d[n-1][W-w_n] + v_n)`，状态d的意义即我们所求的目标--“最大价值”。  

使用普通递归法解题：  
```c++
// Just borrow code from https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
int knapsack_dfs(int n, int W, int ws[], int vs[]) {
    if(n == 0 || W == 0)
        return 0;
    if(W - ws[n-1] < 0)
        return knapsack_dfs(n-1, W, ws, v);
    else
        return max(knapsack_dfs(n-1, W, ws, v), knapsack_dfs(n-1, W-ws[n-1], ws, v) + v[n-1]);
}
```
使用动态规划法解题：
```c++
// Just borrow code from https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
int knapsack_dp(int n, int W, int ws[], int vs[]) {
    int K[n+1][W+1];  
    for(int i = 0; i <= n; ++i) {
        for(int w = 0; w <= W; ++w) {
            if(i == 0 || w == 0)
                K[i][w] = 0; 
            else if(w - ws[i-1] < 0)
                K[i][w] = K[i-1][w];  // no calculation, save time
            else
                K[i][w] = max(K[i-1][w], K[i-1][w-ws[i-1]] + vs[i-1]);
        }
    }
    return K[n][W];
}
```

**习题：**  
* **[**[UVa10616:Divisible Group Sums](https://vjudge.net/problem/UVA-10616)**]** **[**[Solution(C++)]()**]**
* **[**[UVa11341:Term Strategy](https://vjudge.net/problem/UVA-11341)**]** **[**[Solution(C++)]()**]**
* **[**[UVa1213:Sum of Different Primes](https://vjudge.net/problem/UVA-1213)**]** **[**[Solution(C++)]()**]**


## 无穷背包问题

**习题：**  
* **[**[UVa357:Let Me Count The Ways](https://vjudge.net/problem/UVA-357)**]** **[**[Solution(C++)]()**]**
* **[**[UVa11137:Ingenuous Cubrency](https://vjudge.net/problem/UVA-11137)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10313:Pay the Price](https://vjudge.net/problem/UVA-10313)**]** **[**[Solution(C++)]()**]**
