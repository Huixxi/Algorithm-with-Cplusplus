# TSP旅行商问题＆区间DP
"Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?"  
给定一个城市列表包含n个城市，以及每对城市之间的距离（转化成图问题的话就是一个**加权完全图**），有一个商人要拜访这n个城市，而且每个城市只能拜访一次，而且最后要回到起点，问我们怎么安排路线可以使得拜访总路程尽可能短？   
**[** 注意TSP问题和哈密顿圈问题(Hamiltoninan Cycle Problem)的区别，HCP是判断一个图中是否存在一个哈密顿圈，而TSP则是已知存在多个哈密顿圈(因为是完全图)，去求一个权重最小的哈密顿圈 **]**  
* 暴力的复杂度(naive)：$O(n!)$
* 能否用图论中的最短路径算法(Dijkstra等)？ 不可
* 动态规划(DP)算法复杂度：$O(n^2 2^n)$
```
// C(S, i) be the cost of the minimum cost path visiting each vertex in set S exactly once, 
// starting at 1 and ending at i.

If size of S is 2, then S must be {1, i},
    C(S, i) = dist(1, i) 
Else if size of S is greater than 2.
    C(S, i) = min { C(S-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != 1.
```
* 近似算法(Approximate using MST)：[GeeksforGeeks-TSP2](https://www.geeksforgeeks.org/travelling-salesman-problem-set-2-approximate-using-mst/)


Read more about TSP problem:  
* [Wikipedia](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
* [GeeksforGeeks-TSP1](https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/)


**习题：**  
* **[**[UVa10496:Collecting Beepers](https://vjudge.net/problem/UVA-10496)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10721:Bar Codes](https://vjudge.net/problem/UVA-10721)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10943:How do you add?](https://vjudge.net/problem/UVA-10943)**]** **[**[Solution(C++)]()**]**
* **[**[UVa1261:String Popping](https://vjudge.net/problem/UVA-1261)**]** **[**[Solution(C++)]()**]**
* **[**[UVa10003:Cutting Sticks](https://vjudge.net/problem/UVA-10003)**]** **[**[Solution(C++)]()**]**
