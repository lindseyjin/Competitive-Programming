/*
https://leetcode.com/contest/weekly-contest-129/problems/partition-array-into-three-parts-with-equal-sum/
2019-04-05
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        // find total sum
        int sum = 0;
        for (auto it = A.begin(); it != A.end(); ++it) {
            sum += *it;
        }
        
        // find sum of each part
        if (sum % 3 != 0) return false;
        int part = sum/3, tracker = 0, count = 0;
        
        // partitioning
        for (auto it = A.begin(); it != A.end(); ++it) {
            tracker += *it;
            if (tracker == part) {
                tracker = 0;
                count++;
            }
        }
        
        if (count >= 3) return true;
        return false;
    }
};