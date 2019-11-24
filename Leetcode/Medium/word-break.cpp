/*
https://leetcode.com/problems/word-break/
2019-10-27
*/
class Solution {
public:
    bool dp(string s, int begin, vector<string>& wordDict, unordered_set<int>& visited) {
        // memoize failed start indices
        if (visited.count(begin)) return false;
            
        for (int i = 0; i < wordDict.size(); ++i) {
            string word = wordDict[i];
            if (s.substr(begin) == word) return true;
            
            if (s.find(word, begin) != begin) continue;
            if (dp(s, begin + word.length(), wordDict, visited)) return true;
        }
        
        visited.insert(begin);
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<int> visited;
        return dp(s, 0, wordDict, visited);
    }
};