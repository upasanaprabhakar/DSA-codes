class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n= s.length();
        int maxLen=0;
        unordered_map<char,int>mp;
        int maxFreq=0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int len = r-l+1;

            while(len-maxFreq > k){
                mp[s[l]]--;
                l++;
                len = r-l+1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};