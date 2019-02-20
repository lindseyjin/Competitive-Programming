class Solution {
public:
    
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // idea: keep track of visited ones, if conditions
        //conditions to check: are you at boundary? can you go to the next grid
        vector<vector<int>> v;
        int x = r0, y = c0;
        char dir = 'e';
        v.push_back({x, y});  
        int grid[R][C];
        grid[x][y] = true;
        int counter = 1;

        while(counter < R*C) {
            if (dir == 'e') {
                if (y < 0 || !grid[x][y+1]) {
                    
                }
                if (grid[x][y+1]) { // check if taken if so, then keep moving north
                    x--;
                }
                else {
                    y++;
                    dir = 's'; 
                }
            }
            else if (dir == 's') {
                if (grid[x+1][y]) {
                    y++;
                }
                else {
                    x++;
                    dir = 'w';   
                }
            }
            else if (dir == 'w') {
                if (grid[x][y-1]) {
                    x++;
                }
                else {
                    y--;
                    dir = 'n';
                }
            }
            else {
                if (grid[x-1][y]) {
                    y--;
                }
                else {
                    x--;
                    dir = 'e';
                }
            }
            if (x < R && y < C && x >= 0 && y >= 0) {
                v.push_back({x, y});   
                grid[x][y] = true;
                counter++;
            }
            
        }
        return v;
    }
};