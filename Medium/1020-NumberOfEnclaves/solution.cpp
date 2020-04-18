/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/number-of-enclaves/
*/
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || !grid[x][y]) return;
        grid[x][y] = 0;
        dfs(x+1,y,grid);
        dfs(x,y-1,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int ans = 0;
        for(int i=0;i<n-1;++i) {
            dfs(0,i,grid);
            dfs(m-1,n-i-1,grid);
        }
        for(int i=0;i<m-1;++i) {
            dfs(i,n-1,grid);
            dfs(m-i-1,0,grid);
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                ans += grid[i][j];
            }
        }
        return ans;
    }
};