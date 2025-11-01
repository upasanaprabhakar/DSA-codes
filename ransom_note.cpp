class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magamp;

        for(char c: magazine){
            magamp[c]++;
        }

        for(char c : ransomNote){
            if(magamp[c] <= 0){
                return false;
            }
            magamp[c]--;
        }
        return true;
    }
};