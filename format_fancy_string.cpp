class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) {
            return s;
        }

        string result = "";

        for (int i = 0; i < s.length(); i++) {
            char currChar = s[i];

            if (result.length() >= 2 &&
                result[result.length() - 1] == currChar &&
                result[result.length() - 2] == currChar) {
                continue;
            }
            result += currChar;
        }

        return result;
    }
};