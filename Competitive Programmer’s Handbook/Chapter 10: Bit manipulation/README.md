# Bit manipulation

## Corresponding Problems on LeetCode
* Bit Operations
  * Check the kth bit of `x` is `1` or `0`: `x & (1 << k)`
  * Set the kth bit of `x` to `1`: `x | (1 << k)`
  * Set the kth bit of `x` to `0`: `x | ~(1 << k)`
  * Invert the kth bit of `x`: `x ^ (1 << k)`
  * Set the last `1` bit of `x` to `0`: `x & (x - 1)`, e.g `1101` to `1100`
  * Set all the `1` bits to `0`, except for the last `1` bit: `x & -x`, e.g `1101` to `0001`
  * Invert all the bits after the last `1` bit: `x | (x − 1)`, e.g `10100` to `10111`
  * Check a positive number `x` is a power of two: `x & (x - 1) == 0`
* Representing Sets: `int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);  // 1 3 4 8`
  * Intersection: `a & b`
  * Union: `a | b`
  * Complement: `~a`
  * Difference： `a & (~b)`
  * Go through the subsets of a set `x`: `int b = 0; do { // process subset b } while (b=(b-x)&x);`
* Bit Optimizations
  * Hamming Distances: `a^b` [477. Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/)
  * Counting Subgrids: [750. Number Of Corner Rectangles -- Google](https://leetcode.com/problems/number-of-corner-rectangles/)
* Dynamic Programming
  * Optimal selection
  * From permutations to subsets
  * Counting subsets
