class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        int ans = 0;
        for(char c='a';c<='z';c++){
            char m = 'a'+('z'-c);
            if(c<=m){
                ans += abs(mp[c]-mp[m]);
            }
        }

        for(char c='0';c<='9';c++){
            char m = '0'+('9'-c);
            if(c<=m){
                ans += abs(mp[c]-mp[m]);
            }
        }
        return ans;
    }
};