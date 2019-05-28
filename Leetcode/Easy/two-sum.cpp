using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int key;
        vector<int> v;
        
        for (int i = 0; i < nums.size(); i++) {
            key = nums.at(i);
            if (m.count(key) == 1) {
                v.push_back(m.at(key));
                v.push_back(i);
                return v;
            }
            m.insert(pair<int, int>(target - key, i));
        }
    }
};