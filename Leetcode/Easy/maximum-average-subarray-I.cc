class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int maxAvg, currAvg;
        for (int index = 0; index <= nums.size() - k; index++) {
            currAvg = 0;
            for (int x = 0; x < k; x ++) {
                currAvg += (nums.at(index + x));
            }
            if (index == 0 || currAvg > maxAvg) maxAvg = currAvg;
        }
        return (double)maxAvg/(double)k;
    }
};