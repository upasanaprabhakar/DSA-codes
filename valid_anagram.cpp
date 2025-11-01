class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int,int>mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            char ch = t[i];
            if(mp.find(ch)!= mp.end()){
                mp[ch]--;
                if(mp[ch]== 0) mp.erase(ch);
            }
            else return false;
        }
        
        if(mp.size()>0) return false;
        return true;
    }
};