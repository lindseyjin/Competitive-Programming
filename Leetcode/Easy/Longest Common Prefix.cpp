class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int index = 0; 
        int min_index = strs.at(0).length();
        for (int x = 1; x < strs.size(); x++) {
            index = 0;
            while (index < strs.at(0).length() && index < strs.at(x).length()) {
                if (strs.at(0).at(index) == strs.at(x).at(index)) index++;
                else break;
            }
            if (index < min_index) min_index = index;
        }
        return strs.at(0).substr(0, min_index); //substrng to min index
    }
};