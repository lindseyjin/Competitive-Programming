class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x = 0, y = 0, z = 0, zlargest, ylargest;
        for (int i = 0; i < grid.size(); i++) {
            ylargest = 0;
            zlargest = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid.at(i).at(j) != 0) x++;
                if (grid.at(i).at(j) > ylargest) ylargest = grid.at(i).at(j);
                if (grid.at(j).at(i) > zlargest) zlargest = grid.at(j).at(i);
            }
            y += ylargest;
            z += zlargest;
        }
        
        return x + y + z;
    }
};