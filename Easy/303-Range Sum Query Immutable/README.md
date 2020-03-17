# 303 - Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices *i* and *j* (*i* ≤ *j*), inclusive. You may assume that the array doesn't change. You can find the problem [here](https://leetcode.com/problems/range-sum-query-immutable)

## Example

```bash
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
```

## Tags

Dynamic Programming

## Solution

Imagine that we pre-compute the cummulative sum from index *0* to *k*. Could we use this information to derive <img src="https://latex.codecogs.com/gif.latex?sumRange(i,&space;j)" title="sumRange(i,&space;j)" />?
Let us define <img src="https://latex.codecogs.com/gif.latex?sum[k]" title="sum[k]" /> as the cumulative sum for <img src="https://latex.codecogs.com/gif.latex?nums[0&space;\cdots&space;k-1]" title="nums[0 \cdots k-1]" /> (inclusive):
<img src="https://latex.codecogs.com/gif.latex?sum[k]&space;=&space;\left&space;\{&space;\begin{array}{rl}&space;\sum_{i=0}^{k-1}nums[i]&space;&&space;,&space;k&space;>&space;0&space;\\&space;0&space;&,&space;k&space;=&space;0&space;\end{array}&space;\right&space;\}" title="sum[k] = \left \{ \begin{array}{rl} \sum_{i=0}^{k-1}nums[i] & , k > 0 \\ 0 &, k = 0 \end{array} \right \}" />
Now, we can calculate <img src="https://latex.codecogs.com/gif.latex?sumRange" title="sumRange" /> as following:
<img src="https://latex.codecogs.com/gif.latex?sumRange(i,&space;j)&space;=&space;sum[j&space;&plus;&space;1]&space;-&space;sum[i]" title="sumRange(i, j) = sum[j + 1] - sum[i]" />


## Complexity Analysis

 - Time complexity : *O(1)* time per query, *O(n)* time pre-computation. Since the cumulative sum is cached, each sumRange query can be calculated in *O(1)* time.

 - Space complexity : *O(n)*.