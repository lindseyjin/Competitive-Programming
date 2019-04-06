class Solution {
public:
    int subtractAmount(int a, int b) {
        if (a == 0) return 0;
        return a <= b ? a : b;
    }
    
    int surfaceArea(vector<vector<int>>& grid) {
        // each block = 4n+2
        // add and subtract sides from total?
        
        int ans = 0, curr, N = grid.size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                curr = grid.at(i).at(j);
                if (curr != 0) {
                    ans += 4*curr + 2;
                    if (i - 1 >= 0) ans -= subtractAmount(grid.at(i-1).at(j), curr);
                    if (i + 1 < N) ans -= subtractAmount(grid.at(i+1).at(j), curr);
                    if (j - 1 >= 0) ans -= subtractAmount(grid.at(i).at(j-1), curr);
                    if (j + 1 < N) ans -= subtractAmount(grid.at(i).at(j+1), curr);
                }
            }
        }
        return ans;   
    }
};