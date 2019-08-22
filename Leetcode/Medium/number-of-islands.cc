
/*
https://leetcode.com/problems/number-of-islands/
2019-08-21
*/

class Solution {
public:
    
    void markVisitedIslands(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (visited[x][y]) return;
        else visited[x][y] = true;
        
        if (grid[x][y] == '1') {
            if (x > 0) markVisitedIslands(x-1, y, grid, visited);
            if (y > 0) markVisitedIslands(x, y-1, grid, visited);
            if (x < grid.size()-1) markVisitedIslands(x+1, y, grid, visited);
            if (y < grid[0].size()-1) markVisitedIslands(x, y+1, grid, visited);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        if (grid.size() == 0) return islands; // 0 if grid empty
        
        int height = grid.size(), width = grid[0].size();
        vector<vector<bool>> visited (height, vector<bool>(width, false));
        
        // count num islands
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    markVisitedIslands(i, j, grid, visited);
                    islands++;
                }     
            }
        }
            
        return islands;
    }
};