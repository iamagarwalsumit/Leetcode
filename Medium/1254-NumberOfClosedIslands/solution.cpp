/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/number-of-closed-islands/
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool discard;
    void dfs(int x,int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]) return;
        if(x == 0 || x == grid.size()-1 || y == 0 || y == grid[0].size()-1) discard = true; 
        grid[x][y] = 1;
        dfs(x+1,y,grid);
        dfs(x,y-1,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int cnt = 0;
        for(int i=1;i<m-1;++i){
            for(int j=1;j<n-1;++j){
                if(!grid[i][j]){
                    discard = false;
                    dfs(i,j,grid);
                    if(!discard) cnt++;
                }
            }
        }
        return cnt;
    }
};