/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/product-of-array-except-self/
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1);
        int l = 1,r = 1;
        for(int i=0;i<n;++i){
            output[i] *= l;
            output[n-i-1] *= r;
            l *= nums[i];
            r *= nums[n-i-1];
        }
        return output;
    }
};