class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int path = 0;
        if (pairs.size() == 1)  {
            path = 1;
        } else if (pairs.size() > 0) {
            int smallest = pairs.at(0).at(1);
            // find smallest b
            for (int x = 1; x < pairs.size(); x++) {
                if (pairs.at(x).at(1) < smallest)
                    smallest = pairs.at(x).at(1);
            }
            path++;
            // then delete pairs where c < b
            for (int x = 0; x < pairs.size(); x++) {
                if (pairs.at(x).at(0) <= smallest) {
                    pairs.erase(pairs.begin() + x);
                    x--;
                }
            }
            if (pairs.size() > 0) {
                path += findLongestChain(pairs);
                                cout << path;
            }   
        }
        return path;
    }
};