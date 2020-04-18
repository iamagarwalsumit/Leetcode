/*
    Created by
    Sumit Agarwal
    https://leetcode.com/problems/range-sum-query-2d-immutable/
*/
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row>0?matrix[0].size():0;
        sum = vector<vector<int>>(row+1,vector<int>(col+1,0));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */