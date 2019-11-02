/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
2019-11-02
*/
class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    
    void addWord(vector<string>& ans, int i, string digits, string word) {
        if (i == digits.size() && i > 0) {
            ans.push_back(word);
        } else {
            string letters = map[digits[i]];
            for (int x = 0; x < letters.length(); ++x) {
                addWord(ans, i+1, digits, word+letters[x]);
            }
        }   
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;        
        addWord(ans, 0, digits, "");
        return ans;
    }
};