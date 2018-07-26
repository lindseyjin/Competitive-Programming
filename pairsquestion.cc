#include <unordered_map>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

//Question: In a given set of numbers, find all unique map that add up to target
vector <vector <int> > returnmap (vector <int> nums, int target) {
     unordered_map<int, boolean> map;
    
    //add to unordered_map
    for (int x = 0; x < nums.size(); x++) {
        map.insert(nums.at(x), false);
    }

    auto it = map.find(key);
    //iterate through array
    for (int x = 0; x < nums.size(); x++) {
        if ((target - nums.at(x)) != map.end()) 
        it->second = true;
    }
    
    vector <vector <int> > pairs;
    for (auto it2 = map.begin(); it2 != map.end(); it2++) {
        if (it2->second == true) {
            vector <int> v;
            v.push_back(it2->first);
            v.push_back(target-it2->first);
            pairs.push_back(v);
            cout << it2->first << ", " target - (it2->first) << endl; 
        }
    }

    return pairs;
    //Complexity of solution is 
}

int main (int argc, char* argv[]) {
    vector <int> v;
    for (int x = 1; x < 22; x++) 
        v.push_back(x);
    
    vector <vector <int> > pairs = returnmap(v, 18);
    return 0;
}