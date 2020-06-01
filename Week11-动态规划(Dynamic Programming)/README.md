# 动态规划
`"Those who cannot remember the past are condemned to repeat it."    -- Dynamic Programming`   

动态规划是一种带记忆的递归，通过将复杂问题分解成一个简单子问题集合，每个简单子问题只被解决一次并将它们的答案存在一个容器中。每个子问题的答案以某种方式被编号，使之能够被高效的查找，当相同的子问题下一次出现的时候，我们直接取它的答案直接用，而不是重新计算它。      

当使用动态规划解题时，首先要找到子问题（状态），然后明确`dp`数组的含义，明白`dp[i]`或`dp[i][j]`或`dp[i][j][k]`等等代表的是什么，最后寻找状态转移关系。   

## 经典DP问题
### 1.KMP字符匹配问题
给定两个字符串：长度为`m`的模式串`pat`和长度为`n`的文本串`str`。在`str`中查找子串`pat`，如果存在，返回这个子串的起始索引，否则返回`-1`。  




Learn More: [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)   

Practice More: [Top 50 Dynamic Programming Practice Problems](https://blog.usejournal.com/top-50-dynamic-programming-practice-problems-4208fed71aa3)




**习题：**  
* **[**[UVa10684:The jackpot](https://vjudge.net/problem/UVA-10684)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa10755:Garbage Heap](https://vjudge.net/problem/UVA-10755)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa983:Localized Summing for Blurring](https://vjudge.net/problem/UVA-983)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa11951:Area](https://vjudge.net/problem/UVA-11951)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa481:What Goes Up](https://vjudge.net/problem/UVA-481)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa11368:Nested Dolls](https://vjudge.net/problem/UVA-11368)**]** **[**[Solution(C++)][1]**]**

[1]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week01-%E5%9F%BA%E7%A1%80/UVa1585_Score.cpp
