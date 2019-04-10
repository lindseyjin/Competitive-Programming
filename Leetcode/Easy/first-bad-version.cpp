/*
https://leetcode.com/problems/first-bad-version/
2019-04-09
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;    
        
        while (L < R) {
            int index = (R-L)/2 + L;
            if (isBadVersion(index)) R = index;
            else L = index+1;
        }
        
        return R;
    }
};