class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        if (people.size() == 1) return 1;
        bool person_fits;
        int boats = 0;
        
        sort(people.rbegin(), people.rend());
        
        int begin = 0, end = people.size() - 1;
        
        while (begin <= end) {
            if (people.at(begin) + people.at(end) <= limit) {
                end--;
            }
            boats++;
            begin++;
        }
        return boats;
    }
};