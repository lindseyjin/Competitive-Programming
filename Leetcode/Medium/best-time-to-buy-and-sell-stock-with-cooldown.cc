/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
2019-08-24
*/

class Solution {
public:
    
    int findMaxRecursion(int min, int i, vector<int>& p, unordered_map<string, int>& map) {
        string key = to_string(min) + ":" + to_string(i);

        if (map.find(key) != map.end()) return map[key];
            
        if (i >= p.size()-1) { // if at or past end of array
            if (i >= p.size() || p[i] <= p[min]) map[key] = 0;
            else map[key] = p[i] - p[min];
        } else if (p[i] <= p[min]) { // buy current stock instead
            min = i;
            map[key] = findMaxRecursion(min, i+1, p, map);
        } else { // sell stock or continue
            map[key] = max(p[i] - p[min] + findMaxRecursion(i+2, i+3, p, map), findMaxRecursion(min, i+1, p, map));    
        }
        return map[key];
    }
    
    int maxProfit(vector<int>& prices) {   
        if (prices.size() == 0) return 0;
        
        unordered_map<string, int> map;
        return findMaxRecursion(0, 1, prices, map);
    }
};