class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector <int> ans;
        int diff = 0, max_size = A.size() >= B.size() ? A.size(): B.size();
        
        for (int i = 0; i < max_size; i++) {
            if (i < A.size()) diff += A[i];
            if (i < B.size()) diff -= B[i];
        }
        
        diff = diff/2;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] - B[j] == diff) {
                    ans.push_back(A[i]);
                    ans.push_back(B[j]);
                    return ans;
                }
            }
        }
        return ans;
    }
};