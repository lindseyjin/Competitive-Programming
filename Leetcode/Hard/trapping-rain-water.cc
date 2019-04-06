class Solution {
public:

    int find_size(int prevPeak, int nextPeak, vector<int>height) {
        int size = 0;
        int min = height.at(prevPeak) < height.at(nextPeak) ? height.at(prevPeak) : height.at(nextPeak);
        for (int x = prevPeak + 1; x < nextPeak; x++) {
            size += min - height.at(x);
        }
        return size;
    }
    int find_prev_peak(int index, vector<int>height) {
        for (int x = index; x < height.size() - 1; x++){
            if (height.at(x+1) < height.at(x)) 
                return x;
        }
        return -1;
    }
    int find_next_peak(int index, int prevPeak, vector<int> height) {
        int nextPeak = -1, max = 0;
        for (int x = index + 1; x < height.size(); x++) {
            if (height.at(x) >= height.at(prevPeak)) {
                return x;
            }
            if (height.at(x) > max) {
                max = height.at(x);
                nextPeak = x;
            }
        }
        return nextPeak;
    }
    int trap(vector<int>& height) {
        
        // interval = (prevPeak, nextPeak) 
        // prevPeak = first height where next is below
        // nextPeak has to be higher or equal to prevPeak, or highest remaining height
        // once nextPeak is found, calculate size of interval
        // then find next prevPeak (may be nextPeak)
        
        int prevPeak, nextPeak, size = 0;
        if (height.size() <= 2) {
            return size;
        }

        int index = 0;
        while (index < height.size()) {
            prevPeak = find_prev_peak(index, height);
            if (prevPeak == -1){
                break;
            }
            nextPeak = find_next_peak(index, prevPeak, height);
            if (nextPeak == -1){
                break;
            }
            size += find_size(prevPeak, nextPeak, height);
            index = nextPeak;
        }
        return size;
    }
};