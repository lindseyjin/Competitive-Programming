class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.size() == 0) return 0;
        unordered_map<char, string> m;
        string morse [26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        char letter = 'a';
        for (int i = 0; i < 26; i++) {
            m[letter] = morse[i];
            letter++;
        }
        vector<string> morse_words;
        string temp, word;
        for (int index = 0; index < words.size(); index++) {
            temp = "";
            word = words.at(index);
            for (int x = 0; x < word.length(); x++) {
                temp += m[word.at(x)];
            }
            if (find(morse_words.begin(), morse_words.end(), temp) == morse_words.end()) {
                morse_words.push_back(temp);
            }
        }
        return morse_words.size();
    }
};