/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/edit-distance/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    typedef vector<vector<int>> VVI;
    typedef vector<int> VI;
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();
        VVI dp(2,VI(n+1,0)); // O(2n) space
        for(int i=0;i<=n;++i) dp[0][i] = i;
        for(int i=1;i<=m;++i){
            dp[i%2][0] = i; 
            for(int j=1;j<=n;++j){
                dp[i%2][j] = (a[i-1]==b[j-1])?dp[1-(i%2)][j-1]:min(dp[1-(i%2)][j-1],min(dp[i%2][j-1],dp[1-(i%2)][j]))+1;
            }
        }
        return dp[m%2][n]; 
    }
    
};