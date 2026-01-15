class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n= s.length();
        int m= p.length();
        vector<int> result;
        if(m>n) return result;
        vector<int>freqP(26,0),freqS(26,0);

        //freq of p
        for(char c: p){
            freqP[c-'a']++;
        }

        //sliding window on s
        for(int r=0;r<n;r++){
            freqS[s[r]-'a']++;

            if(r>=m){
                freqS[s[r-m]-'a']--;
            }

            if(freqP == freqS){
                result.push_back(r-m+1);
            }
        }
        return result;
    }
};