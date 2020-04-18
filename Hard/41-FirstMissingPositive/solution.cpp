/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/first-missing-positive/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
    int firstMissingPositive1(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]< 0 || nums[i]>n) nums[i] = 0;
        }
        int m = n+1;
        for(int i=0;i<n;++i){
            int pre = nums[i]%m ;
            if(pre>0) nums[pre-1] =  pre*m + (nums[pre-1]%m);
        }
        for(int i=0;i<n;++i){
            if(nums[i]/m != i+1) return i+1;
        }
        return n+1;
    }
};