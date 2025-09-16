class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>freq;
        int maxVowel= 0, maxConso= 0;

        for(char c: s){
            freq[c]++;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                maxVowel = max(maxVowel, freq[c]);
            }
            else{
                maxConso = max(maxConso, freq[c]);
            }
        }
        return maxVowel + maxConso;
    }
};