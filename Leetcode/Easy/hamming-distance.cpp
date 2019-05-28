class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        int max_length = max(log2(x), log2(y));
        int bit_x, bit_y;
        
        for (int i = max_length; i >= 0; i--) {
            bit_x = x >> i & 1;
            bit_y = y >> i & 1;            
            if ((bit_x ^ bit_y) != 0) diff++;
        }
        
        return diff;
    }
};