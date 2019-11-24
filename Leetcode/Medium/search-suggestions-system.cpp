/**
https://leetcode.com/problems/search-suggestions-system/
2019-11-23
**/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> searchList;
        vector<string> search;
        
        // sort lexicographically
        sort(products.begin(), products.end());
        
        int start = 0;
        
        for (int i = 0; i < searchWord.length(); ++i) {
            int counter = 0;
            search.clear();
            for (int j = start; j < products.size(); ++j) {
                if (i < products[j].length() && products[j][i] == searchWord[i]) {
                    if (products[j].substr(0,i) == searchWord.substr(0,i)) {
                        search.push_back(products[j]);
                        counter++;
                        if (counter == 1) start = j;
                    } else break;
                }
                if (counter == 3) break;
            }            
            searchList.push_back(search);
        }
        
        return searchList;
    }
};