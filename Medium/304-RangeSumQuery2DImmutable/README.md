# 304 - Range Sum Query 2D - Immutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (*row1*, *col1*) and lower right corner (*row2*, *col2*). You may assume that the array doesn't change. You can find the problem [here](https://leetcode.com/problems/range-sum-query-2d-immutable/).

![304 - Range Sum Query 2D - Immutable - Problem](https://leetcode.com/static/images/courses/range_sum_query_2d.png)

## Example

```bash
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
```

## Tags

Dynamic Programming

## Solution

![304 - Range Sum Query 2D - Immutable - Solution](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Medium/304-RangeSumQuery2DImmutable/solution.png)

## Complexity Analysis

 - Time complexity : `O(1)` time per query, `O(mn)` time pre-computation. Since the cumulative sum is cached, each `sumRegion` query can be calculated in `O(1)` time.

 - Space complexity : `O(mn)`. The algorithm uses `O(mn)` space to store the cumulative region sum.