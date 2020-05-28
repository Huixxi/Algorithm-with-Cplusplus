# 线段树(Segment Tree)
在解决一个数组中的区间查询时(一个区间中的最大值、最小值、区间和等)，通常要考虑使用线段树。   
[Maybe the Best Tutorial -- Tushar Roy's Segment Tree Range Minimum Query](https://www.youtube.com/watch?v=ZBHKZF5w4YU)     
以下解释均来自于上面Tushar大佬的视频。    

**举个例子：**  
> 一个数组`[-1, 3, 4, 0, 2, 1]`，我们想查询0到3区间内的最小值。   
```
// segment 
[-1, 3, 4, 0, 2, 1]
[-1, 3, 4] | [0, 2, 1]
[-1, 3] | [4] | [0, 2] | [1]
```

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
![线段树结构](https://raw.githubusercontent.com/Huixxi/Algorithm-with-Cplusplus/master/AlgorithmImages/segtree.png)
当在线段树中查询某区间x到y时，有三种基本情况：
* 查询区间`[x, y]`与树中某节点区间部分重叠，往两个方向走；
* 查询区间`[x, y]`与树中某节点区间完全重叠，返回节点值；
* 查询区间`[x, y]`与树中某节点区间无重叠，返回一个很大的值（这里是求区间最小，因情况而定）；

**如何建树**    
* 假如原数组的长度`l`是2的几次方（2，4，8，16...），则构建的线段树数组的长度为`2*l - 1`，如`l=4, t_l=2*4-1 = 7`
* 假如原数组的长度`l`不是2的几次方，则找比`l`大的那个最小2的几次方`lnew`，则构建的线段树数组的长度为`2*lnew - 1`，如`l=5, lnew=8, t_l=2*8-1 = 15`

最坏情况下查询一次的时间复杂度为`O(4logn)`，空间复杂度为`O(4n)`。   

举个例子：`[-1, 0, 3, 6]`.
``` 
     -1
    /  \
  -1    3
 /  \  /  \
-1  0  3  6
```
则其对应的线段树数组为`[-1, -1, 3, -1, 0, 3, 6], i = 0,1,2...`。下标为`i`的节点的左子节点为`2i+1`，右子节点为`2i+2`，父节点为`(i-1)/2`。
```c++
/*
 input : input array
 segTree : segment tree array
 low : lowest index of input array, initially 0
 high : highest index of input array, initially input.length() - 1
 pos : root index of segment tree array, initially 0
*/
void constructTree(int input[], int segTree[], int low, int high, int pos) {
    if(low == high) {  // leaf node
        segTree[pos] = input[low];
        return;
    }
    int mid = low + (high - low) / 2;
    constructTree(input, segTree, low, mid, 2*pos+1);  // left child node
    constructTree(input, segTree, mid+1, high, 2*pos+2);  // right child node
    segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}
```

**区间查询**    
```c++
/*
 segTree : built segment tree array
 qlow : lowest index of query range
 qhigh : highest index of query range
 low : lowest index of input array, initially 0
 high : highest index of input array, initially input.length() - 1
 pos : root index of segment tree array, initially 0
*/
void rangeminQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos) {
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qlow > high || qhigh < low)
        return INT_MAX;
    int mid = low + (high - low) / 2;
    return min(rangeminQuery(segTree, qlow, qhigh, low, mid, 2*pos+1, 
               rangeminQuery(segTree, qlow, qhigh, mid+1, high, 2*pos+2);
}
```

**区间更改--懒惰传播(Lazy Propagation Segment Tree)**
* Increment `[0, 3]` by 3
* Increment `[0, 2]` by 1
* Increment `[4, 6]` by -1
* Query min in `[3, 5]`

当不使用Lazy Propagation的时候，每次区间更新我们都会从头结点到叶子节点进行`O(logn)`的操作。懒惰传播的整体思想为，当且仅当我们必须要修改某一节点的值的时候我们再去修改，否则我们只是做个记录，以减少一些不必要的更新操作。每当我们达到某一节点的时候，无论是更新还是查询操作，第一件事是检查过去更新的所有值是否被应用了，即这个值是不是被更新到最新了，假如lazy数组中的该节点值为非零，那么说明过去的更新操作，没有被完全应用。    
首先，检查该节点时候已更新到最新，若Lazy中该节点的值不为0，则更新Seg树中该节点的值，并将Lazy树中该节点的值向下传播给其子节点，再将Lazy树中该节点的值置0；
* 操作区间`[x, y]`与树中某节点区间部分重叠，往两个方向走，回溯过程更新Seg树中节点的值；
* 操作区间`[x, y]`与树中某节点区间完全重叠，停止，更新Seg树的该节点的值，同时更新Lazy树中相应节点的左右节点+=操作值；
* 操作区间`[x, y]`与树中某节点区间无重叠，返回。

```c++
/*
 lazy[] is the same size as segTree[]
 segTree : [-1, -1, 3, -1, 0, 3, 6]
 lazyTree : [0, 0, 0, 0, 0, 0, 0]
*/
void updateSegmentTreeLazy(int segTree[], int lazy[], int olow, int ohigh, int delta, int low, int high, int pos) {
    if(low > high)
        return;
    // check the pos node in lazyTree
    if(lazy[pos] != 0) {
        segTree[pos] += lazy[pos];
        if(low != high) {  // non-leaf nodes
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    
    // no overlap condition
    if(olow > high || ohigh < low)
        return;
    
    // total overlap
    if(low >= olow && high <= ohigh) {
        segTree[pos] += delta;
        if(low != high) {  // non-leaf nodes
            lazy[2*pos+1] += delta;
            lazy[2*pos+2] += delta;
        }
        return;
    }
    
    // partial overlap
    int mid = low + (high - low) / 2;
    updateSegmentTreeLazy(segTree[], lazy[], olow, ohigh, delta, low, mid, 2*pos+1);
    updateSegmentTreeLazy(segTree[], lazy[], olow, ohigh, delta, mid+1, high, 2*pos+2);
    segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}
```

```c++
/*
 segTree : built segment tree array
 qlow : lowest index of query range
 qhigh : highest index of query range
 low : lowest index of input array, initially 0
 high : highest index of input array, initially input.length() - 1
 pos : root index of segment tree array, initially 0
*/
void rangeminQueryLazy(int segTree[], int lazy[], int qlow, int qhigh, int low, int high, int pos) {
    if(low > high)
        return INT_MAX;
    // check the pos node in lazyTree
    if(lazy[pos] != 0) {
        segTree[pos] += lazy[pos];
        if(low != high) {  // non-leaf nodes
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    
    if(qlow <= low && qhigh >= high)
        return segTree[pos];
    if(qlow > high || qhigh < low)
        return INT_MAX;
    int mid = low + (high - low) / 2;
    return min(rangeminQueryLazy(segTree, lazy, qlow, qhigh, low, mid, 2*pos+1, 
               rangeminQueryLazy(segTree, lazy, qlow, qhigh, mid+1, high, 2*pos+2);
}
```




**习题：**  
* **[**[UVa11235:Frequent values](https://vjudge.net/problem/UVA-11235)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa11402:Ahoy, Pirates!](https://vjudge.net/problem/UVA-11402)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa1232:SKYLINE](https://vjudge.net/problem/UVA-1232)**]** **[**[Solution(C++)][1]**]**
* **[**[UVa12532:Interval Product](https://vjudge.net/problem/UVA-12532)**]** **[**[Solution(C++)][1]**]**

[1]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week06-%E7%BA%BF%E6%AE%B5%E6%A0%91(Segment%20Tree)/UVa11235_Frequent%20values.cpp
[2]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week06-%E7%BA%BF%E6%AE%B5%E6%A0%91(Segment%20Tree)/UVa11402_Ahoy%2C%20Pirates!.cpp
[3]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week06-%E7%BA%BF%E6%AE%B5%E6%A0%91(Segment%20Tree)/UVa1232_SKYLINE.cpp
[4]: https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/Week06-%E7%BA%BF%E6%AE%B5%E6%A0%91(Segment%20Tree)/UVa12532_Interval%20Product.cpp
