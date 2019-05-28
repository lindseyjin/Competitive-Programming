class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        // use a hashmap and increment every time
        // use -1 as invalid value
        
        int judge = -1;
        
        if (trust.size() == 0 && N == 1) return 1;
        
        std::unordered_map<int, int> town;
        
        for (int i = 0; i < trust.size(); i++) {
            // set a as invalid -> cannot be town judge
            
            town[trust[i][0]] = -1;
            
            if (town[trust[i][1]] != -1) {
                town[trust[i][1]]++;    
            }
        }
        
        // find judge
        for (auto it : town) {
            if (it.second == N - 1) {
                // check if "judge" already exists
                if (judge != -1) {
                    judge = -1;
                    break;
                } else {
                    judge = it.first;
                }
            }
        }
        return judge;
    }
};