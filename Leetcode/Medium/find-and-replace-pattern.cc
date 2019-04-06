class Solution {
public:
    bool sameIndexes (string pattern, string word, int i) {
        char p = pattern.at(i), w = word.at(i);
        int index = 0;
        while (index != -1) {
            if (pattern.find(p, index) != word.find(w, index)) return false;
            index = pattern.find(p, index + 1); 
        }
        return true;
    } 
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // idea: to establish pattern, go through each index, and return array of indexes -> must match
        
        vector<string> ans;
        bool match;
        
        for (int x = 0; x < words.size(); x++) {
            match = true;
            for (int i = 0; i < pattern.length(); i++) {
                if (sameIndexes(pattern, words.at(x), i) == false) {
                    match = false;
                    break;
                }
            }
            if (match == true) ans.push_back(words.at(x));
        }
        
        return ans;
    }
};