class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m>n) return false;

        vector<int> freq1(26,0), freq2(26,0);
        for(char c: s1){
            freq1[c-'a']++;
        }

        for(int r=0;r<n;r++){
            freq2[s2[r]-'a']++;

            if(r >= m){
                freq2[s2[r-m] - 'a']--;
            }
            if(freq1 == freq2) return true;
        }
        return false;
    }
};