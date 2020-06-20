# Greedy Algorithm
贪心算法的意思是每次都选择在当前看起来最优的那一个。设计一个贪心算法的难点在于如何设计一个贪心策略，局部最优的选择也应同样是全局最优选择。      

## Corresponding Problems on LeetCode
* Coin Problem
* Scheduling
  * [646. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)
* Tasks and deadlines
  * Just perform the tasks sorted by their durations in increasing order
* Minimizing sums `|a1 − x|^c + |a2 − x|^c + ... + |an − x|^c`.
  * `c = 1`: choose `x` be the *median*
  * `c = 2`: choose `x` be the *average*
