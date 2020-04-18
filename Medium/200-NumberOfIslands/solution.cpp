/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/number-of-islands/
*/

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
        dfs(x,y-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int cnt = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};