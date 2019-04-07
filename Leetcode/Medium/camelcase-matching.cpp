/*
https://leetcode.com/contest/weekly-contest-131/problems/camelcase-matching/
2019-04-06
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> matchWords;
        
        for (int s = 0; s < queries.size(); s++) {
            string word = queries.at(s);
            int counter = 0;
            bool match = true;
            for (int i = 0; i < word.length(); i++) {
                if (counter < pattern.length() && word.at(i) == pattern.at(counter)) {
                    counter++;
                } else if (word.at(i) < 'a' || word.at(i) > 'z') {
                    match = false;
                    break;
                }
            }
            if (counter < pattern.length()) match = false;
            matchWords.push_back(match);
        }
        
        return matchWords;
    }
};