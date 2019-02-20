class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int increase = 0;
        vector <int> v, h;
        int v_max, h_max;
        
        for (int i = 0; i < grid.size(); i++) {
            v_max = 0;
            h_max = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid.at(i).at(j) > h_max) h_max = grid.at(i).at(j);
                if (grid.at(j).at(i) > v_max) v_max = grid.at(j).at(i);
            }
            v.push_back(v_max);
            h.push_back(h_max);
        }
        
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < h.size(); j++) {
                if (grid.at(i).at(j) < min(v.at(j), h.at(i))) increase += min(v.at(j), h.at(i)) - grid.at(i).at(j);
            }
        }
        return increase;
    }
};