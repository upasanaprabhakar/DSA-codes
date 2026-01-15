class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n = s.length();
        unordered_map<char,int> mp;
        int maxLen = 0;
        int len;

        for(int r=0;r<n;r++){
            mp[s[r]]++;

            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            
            int len = r-l+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};