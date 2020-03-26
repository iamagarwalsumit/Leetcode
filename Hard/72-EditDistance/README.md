# 72 - Edit Distance

Given two words *word1* and *word2*, find the minimum number of operations required to convert *word1* to *word2*. You have the following 3 operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

You can find the problem [here](https://leetcode.com/problems/edit-distance/).

## Example

```bash

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

## Tags

Dynamic Programming

## Solution

![72 - Edit Distance - Solution-1](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Hard/72-EditDistance/solution1.png)

![72 - Edit Distance - Solution-2](https://raw.githubusercontent.com/iamagarwalsumit/Leetcode/master/Hard/72-EditDistance/solution2.png)

## Complexity Analysis

 - Time complexity : *O(mn)* as it follows quite straightforward for the inserted loops.

 - Space complexity : *O(2n)*. The algorithm uses *O(2n)* space because at any step only the previous row of the matrix is required. Hence only two arrays, each of length n can be used and each array can be used to store the computation of the (m%2)th loop using the other array.