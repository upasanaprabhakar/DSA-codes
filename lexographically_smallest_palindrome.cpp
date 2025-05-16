class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i= 0;
        int j= s.length()-1;
        while(i<j){
            s[i]= min(s[i],s[j]);
            s[j]= s[i];
            i++;
            j--;
        }
        return s;
    }
};