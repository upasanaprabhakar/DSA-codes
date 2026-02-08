class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        unordered_map<char,int> need, window; // need-> target freq
                                              //window-> current freq
        //build freq map for t
        for(char c: t){
            need[c]++;
        }

        int required = need.size();  //total required chars
        int formed = 0;

        int l=0, r=0;
        int minLen=INT_MAX;
        int start=0;  //chars satisfied

        while(r<s.size()){
            char c = s[r];
            window[c]++;

            //check if this character is satisfied
            if(need.count(c) && window[c] == need[c]){
                formed++;
            }

            while(l<=r && formed == required){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if(need.count(c) && window[leftChar] < need[leftChar]){
                    formed--;
                }
                l++;
            }

            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};