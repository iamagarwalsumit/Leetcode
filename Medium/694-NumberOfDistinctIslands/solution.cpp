/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/number-of-distinct-islands/
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // direction Approach
    void dfs_dir(int x,int y,vector<vector<int>>& grid,string& path,char dir){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y]) return;
        grid[x][y] = 0;
        path.push_back(dir);
        dfs(x+1,y,grid,path,'d'); // down
        dfs(x,y-1,grid,path,'l'); // left
        dfs(x-1,y,grid,path,'u'); // up
        dfs(x,y+1,grid,path,'r'); // right
        path.push_back('b'); // back
    }
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int cnt = 0;
        set<string> s;
        string path;
        for(int i = 0;i < m;++i) {
            for(int j = 0;j < n;++j) {
                if(grid[i][j]){
                    path = "";
                    dfs_dir(i,j,grid,path,'o'); // origin
                    s.insert(path);
                }
            }
        }
        return s.size();
    }

    // offset Approach
    void dfs_offset(int x,int y,vector<vector<int>>& grid,string& path,int x0,int y0){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y]) return;
        grid[x][y] = 0;
        path += to_string((x-x0)) + "" + to_string((y-y0));
        dfs(x+1,y,grid,path,x0,y0); // down
        dfs(x,y-1,grid,path,x0,y0); // left
        dfs(x-1,y,grid,path,x0,y0); // up
        dfs(x,y+1,grid,path,x0,y0); // right
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        int cnt = 0;
        set<string> s;
        string path;
        for(int i = 0;i < m;++i) {
            for(int j = 0;j < n;++j) {
                if(grid[i][j]){
                    path = "";
                    dfs_offset(i,j,grid,path,i,j); // origin
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
    
};