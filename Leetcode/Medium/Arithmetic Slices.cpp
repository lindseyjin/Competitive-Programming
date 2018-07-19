#include <cmath>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int diff, N = A.size(), sum = 0;
        vector <vector <int> > arith_seqs;  
        vector <int> v;
        
        if (N < 3) return 0;
    
        diff = A[1] - A[0];
        v.push_back(A[0]);
        
        //if A is arithmetic slice > 3, then all possible combos of 3 are also slices
        //if A != arithmetic slice but is > 3, split it into smaller arrays -> use recursion? 
        
        //another idea: make 'splices' up until break in pattern, return all combos of each splice?
        
        for (int x = 1; x < N - 1; x++) {
            v.push_back(A[x]);
            if (A[x + 1] - A[x] != diff) { //start new seq
                arith_seqs.push_back(v);
                v.clear();
                diff = A[x+1] - A[x];
                v.push_back(A[x]);
            }       
        }
        v.push_back(A[N - 1]); //last seq needs to be pushed back
        arith_seqs.push_back(v);
        
        //check for all possible splices
        
        for (int s = 0; s < arith_seqs.size(); s++) {
            int vs = arith_seqs.at(s).size();
            if (vs >= 3) sum += (vs-2)*(vs-1)/2;
        } 
        
        return sum;
    }
};