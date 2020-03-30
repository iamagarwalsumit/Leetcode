# 41 - First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer. Your algorithm should run in O(n) time and uses constant extra space.

You can find the problem [here](https://leetcode.com/problems/first-missing-positive/).

## Example

```bash
Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

```

## Tags

Array

## Solution

The basis of a constant space solution is to use the array itself as a hash table for the elements present in the range [1,n].

### Solution 1: 

- Given size of the array as `n`, we simply ignore elements which are `<= 0 or > n`. The key here is to use swapping to keep constant space and also make use of the length of the array, which means there can be at most n positive integers. 

- For each element `A[i]`, its right place in the array is `A[A[i]-1]`. If the element is not in its right place, just swap `A[i]` and `A[A[i]-1]`. The swap is included in a `while` loop, because after swapping the new element that comes in the place of `A[i]`, can again require to be swapped. 
    > Given A = [3,1,2]. 
    > For A[0] = 3, the correct position is index 2, hence we swap A[0] and A[2] to get [2,1,3]. 
    > Now again for A[0] = 2, the correct index is 1, hence we swap A[0] and A[1] to get [1,2,3]. 

- Next, we check for which i, `A[i] != i+1` and that `i+1` is the missing number. If no such number is found then simply return `n+1`. 

![41 - First Missing Poisitve - Solution-1](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Hard/41-FirstMissingPositive/solution-1.png)

### Solution 2:

- This solution uses the technique of encoding two integers into one with possibility to decode it to both integers back.
    > If we have two integers `k` and `m` such that `m < n`, we can encode and decode them using the formula below:
    > **Encoding** : `r = k * n + m (m < n)` 
    > **Decoding** : `k = r / n`, `m = r % n`

- We want to "serialize" all values to their indices. So `1` will come to `A[0]`, `2` to      `A[1]`. Essentially, `A[i]` will be encoded in `A[A[i]-1]` (just like the above solution). After this we can easily find the "gap". This is an easy task if we could use extra memory for another array. But we cannot. So we can use the "encoding" scheme offered above.
    - Clean every non-relevant item from the array to match the restriction m < n.
    - Encode `A[i]` using the above encoding scheme to store in `A[A[i]-1]`, ensuring `m < n` (the % in the second part ensures that)
    - Find the gap through the decoding technique, retrieving back `i+1` from `nums[i]`.

![41 - First Missing Poisitve - Solution-2](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Hard/41-FirstMissingPositive/solution-2.png)

## Complexity Analysis

 - Time complexity : `O(n)`. 
    - For the first solution, consider position with `A[i]` = `i+1` as a CORRECT SLOT.
        > CORRECT SLOT will never be changed: for CORRECT SLOT, `A[A[i] - 1]` always equals to `A[i]`, vice versa.
        > For each swap, the number of CORRECT SLOT increases by at least 1: Position `A[A[i] - 1] = A[i]` becomes a CORRECT SLOT after swap, and according to (1), this must be a new CORRECT SLOT
        >The maximum of CORRECT SLOT `<= n`
        > Therefore, the complexity is `O(n)`

    - For the second solution it is pretty straightforward that the time complexity is `O(n)`. 

 - Space complexity : `O(1)`. The array is itself used as a hash table/bookkeeping.