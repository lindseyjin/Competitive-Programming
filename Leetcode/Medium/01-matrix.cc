/*
2018-05-28
https://leetcode.com/problems/01-matrix
*/

class Solution {
public:
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> distances(matrix.size(), vector<int>(matrix[0].size(), matrix.size() + matrix[0].size() - 2));
            
        // two passes -> O(n*m) runtime
        // first pass -> bottom -> down, left -> right
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    distances[i][j] = 0;
                } else {
                    if (i > 0) distances[i][j] = min(distances[i][j], 1 + distances[i-1][j]); 
                    if (j > 0) distances[i][j] = min(distances[i][j], 1 + distances[i][j-1]);
                }
            }
        }
        
        // second pass -> bottom -> top, right -> left
        for (int i = matrix.size()-1; i >= 0; --i) {
            for (int j = matrix[0].size()-1; j >= 0; --j) {
                if (i < matrix.size()-1) distances[i][j] = min(distances[i][j], 1 + distances[i+1][j]); 
                if (j < matrix[0].size()-1) distances[i][j] = min(distances[i][j], 1 + distances[i][j+1]);
            }
        }
        
        return distances;
    }
};