# 303 - Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices *i* and *j* (*i* ≤ *j*), inclusive. You may assume that the array doesn't change. You can find the problem [here](https://leetcode.com/problems/range-sum-query-immutable).

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

![303 - Range Sum Query - Immutable - Solution](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Easy/303-RangeSumQueryImmutable/solution.png)

## Complexity Analysis

 - Time complexity : *O(1)* time per query, *O(n)* time pre-computation. Since the cumulative sum is cached, each *sumRange* query can be calculated in *O(1)* time.

 - Space complexity : *O(n)*.