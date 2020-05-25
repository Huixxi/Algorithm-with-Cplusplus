# 线段树(Segment Tree)
在解决一个数组中的区间查询时(一个区间中的最大值、最小值、区间和等)，通常要考虑使用线段树。   
[Maybe the Best Tutorial -- Tushar Roy's Segment Tree Range Minimum Query](https://www.youtube.com/watch?v=ZBHKZF5w4YU) 以下解释均来自于上面Tushar大佬的视频。    

**举个例子：**  
> 一个数组`[-1, 3, 4, 0, 2, 1]`，我们想查询0到3区间内的最小值。   

**方法1**   
直接通过遍历0到3区间，得到其最小值为-1，当有m次查询时，该方法的时间复杂度为`O(m*n)`，空间复杂度为`O(1)`。

**方法2**   
通过一个二维数组维护所有区间中的最小值：
```
   0  1  2  3  4  5
0 -1 -1 -1  0  0  0
1     3  3  0  0  0
2        4  0  0  0
3           0  0  0
4              2  1
5                 1
```
该方法的查询时间复杂度为`O(1)`，构建数组的时间复杂度为`O(n^2)`，空间复杂度为`O(n^2)`。


**方法3 -- 线段树**   
该方法的查询时间复杂度为`O(logn)`，建树的时间复杂度为`O(n)`，空间复杂度为`O(n)`。   
线段树是一棵二叉树，叶子节点为数组中的元素。







**习题：**  
* **[**[UVa11235:Frequent values](https://vjudge.net/problem/UVA-11235)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa11402:Ahoy, Pirates!](https://vjudge.net/problem/UVA-11402)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa1232:SKYLINE](https://vjudge.net/problem/UVA-1232)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa12532:Interval Product](https://vjudge.net/problem/UVA-12532)**]** **[**[Solution(C++)][1]**]**

[1]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week01-%E5%9F%BA%E7%A1%80/UVa1585_Score.cpp
