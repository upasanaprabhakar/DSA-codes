class Solution {
public:
    bool vowel(int ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    bool isValid(string word) {
        int n = word.length();
        if (n < 3)
            return false;
        int v_count = 0;
        int c_count = 0;

        for (int i = 0; i < n; i++) {
            if (!isalnum(word[i]))
                return false;
            if (isalpha(word[i])) {
                if (vowel(tolower(word[i]))) {
                    v_count++;
                } else {
                    c_count++;
                }
            }
        }
        if (!c_count || !v_count)
            return false;
        return true;
    }
};