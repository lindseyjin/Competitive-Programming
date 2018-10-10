class Solution {
public:
    string reverseOnlyLetters(string S) {

        if (S.length() == 0) return S;
        
        string ans = "";
        vector<int> non_letters; 
        char temp;
        
        // reverse string and store indexes of non letters
        for (int i = S.length() - 1; i >= 0; i--) {
             if ((S.at(i) >= 'A' && S.at(i) <= 'Z') || (S.at(i) >= 'a' && S.at(i) <= 'z')) {
                ans += S.at(i); 
            } else {
                non_letters.push_back(i);   
            }
        }
        
        // insert non_letters
        for (int i = non_letters.size() - 1; i >= 0; i--) {
            temp = non_letters.at(i);
            ans = ans.substr(0, temp) + S.at(temp) + ans.substr(temp);
        }
        
        return ans;
    }
};