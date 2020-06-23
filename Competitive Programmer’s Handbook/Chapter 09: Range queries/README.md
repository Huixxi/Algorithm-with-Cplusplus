# Range queries

## Corresponding Problems on LeetCode
* Static array queries(the array values are never updated between the queries)
  * Sum queries -- prefix sum array(1D,2D)
  * Minimum queries -- min(a, b) = min(min(a, a+k−1), min(b−k+1, b)).
* Binary indexed tree
  * [Fenwick Tree树状数组](https://github.com/Huixxi/Algorithm-with-Cplusplus/blob/master/%E7%AE%97%E6%B3%95%E5%8D%9A%E5%AE%A2(Algorithm%20Blogs)/Fenwick%20Tree(%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84).md)
* Segment tree
  * [线段树(Segment Tree)](https://github.com/Huixxi/Algorithm-with-Cplusplus/tree/master/Week06-%E7%BA%BF%E6%AE%B5%E6%A0%91(Segment%20Tree))
* Additional techniques
  * Index compression -- This can be done if we know all the indices needed during the algorithm beforehand.
  * Range updates -- difference array, The advantage of the difference array is that we can update a range in the
original array by changing just two elements in the difference array. More generally, to increase the values in range `[ a, b ]` by `x`, we increase the value at position `a` by `x` and decrease the value at position `b + 1` by `x`.
