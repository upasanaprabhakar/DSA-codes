class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        istringstream stream(s);
        string word;
        int i = 0;

        while (stream >> word) {
            if (i >= pattern.size()) return false;

            char currentChar = pattern[i];

            if (charToWord.count(currentChar)) {
                if (charToWord[currentChar] != word) {
                    return false;
                }
            } else {
                charToWord[currentChar] = word;
            }

            if (wordToChar.count(word)) {
                if (wordToChar[word] != currentChar) {
                    return false;
                }
            } else {
                wordToChar[word] = currentChar;
            }

            i++;
        }

        return i == pattern.size();
    }
};
