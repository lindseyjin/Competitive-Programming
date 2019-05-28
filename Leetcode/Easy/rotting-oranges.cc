/*
https://leetcode.com/problems/rotting-oranges/
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        vector<vector<int>> currentRotten;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // find all rotten oranges
                if (grid[i][j] == 2) currentRotten.push_back({i, j});
            }
        }
        
        vector<vector<int>> newlyRotten;
        vector<vector<int>> gridCopy = grid;
        
        while (currentRotten.size() > 0) {
            for (int i = 0; i < currentRotten.size(); i++) {
                int x = currentRotten[i][0];
                int y = currentRotten[i][1];
                
                // find nearby oranges
                if (x > 0 && gridCopy[x-1][y] == 1) {
                    newlyRotten.push_back({x-1, y});
                    gridCopy[x-1][y] = 2;
                } 
                if (y > 0 && gridCopy[x][y-1] == 1) {
                    newlyRotten.push_back({x, y-1});
                    gridCopy[x][y-1] = 2;
                }
                if (x < grid.size()-1 && gridCopy[x+1][y] == 1) {
                    newlyRotten.push_back({x+1, y});
                    gridCopy[x+1][y] = 2;
                }
                if (y < grid[0].size()-1 && gridCopy[x][y+1] == 1) {
                    newlyRotten.push_back({x, y+1});
                    gridCopy[x][y+1] = 2;
                }
            }
            if (newlyRotten.size() == 0) break;
            currentRotten = newlyRotten;
            newlyRotten.clear();
            min++;
        }
                
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (gridCopy[i][j] == 1) return -1;
            }
        }
        return min;
    }
};