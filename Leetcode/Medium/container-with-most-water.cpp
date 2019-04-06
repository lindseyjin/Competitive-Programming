class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, max_area = 0, begin = 0, end = height.size() - 1;

        while (begin <= end) {
            area = (end - begin)*min(height.at(begin), height.at(end));
            if (area > max_area) max_area = area;
            height.at(begin) < height.at(end)? begin++ : end--;
        }
        
        return max_area;
    }
};