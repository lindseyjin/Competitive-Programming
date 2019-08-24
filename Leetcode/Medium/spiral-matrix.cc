
/*
https://leetcode.com/problems/spiral-matrix/
2019-08-24
*/

class Solution {
public:

    // helper functions
    
    // add all elements in row from begin -> end inclusive
    void traverseRow(bool right, int begin, int end, vector<int>& row, vector<int>& ans) {
        if (right) {
            for (int i = begin; i <= end; ++i) {
                ans.push_back(row[i]);
            }
        } else {
            for (int i = end; i >= begin; --i) {
                ans.push_back(row[i]);
            }
        } 
    }
    
    // add all elements in col from begin -> end inclusive
    void traverseCol(bool down, int begin, int end, int col, vector<vector<int>>& matrix, vector<int>& ans) {
        if (down) {
            for (int i = begin; i <= end; ++i) {
                ans.push_back(matrix[i][col]);
            }
        } else {
            for (int i = end; i >= begin; --i) {
                ans.push_back(matrix[i][col]);
            }    
        } 
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if (matrix.size() == 0) return ans;
        
        int beginRow = 0, endRow = matrix[0].size()-1;
        int beginCol = 0, endCol = matrix.size()-1;
        
        bool right = true;
        bool down = true;
        
        while (beginRow <= endRow) {
            traverseRow(right, beginRow, endRow, right ? matrix[beginCol] : matrix[endCol], ans);
            if (right) beginCol++;
            else endCol--;
            right = !right;
                        
            if (beginCol > endCol) break;

            traverseCol(down, beginCol, endCol, down ? endRow : beginRow, matrix, ans);
            if (down) endRow--;
            else beginRow++;
            down = !down;            
        }
        
        return ans;
    }
};