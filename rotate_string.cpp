class Solution {
public:
    bool rotateString(string s, string goal) {
        int m=s.length();
        int n=goal.length();
        if(m!=n){
            return false;
        }
        for(int i=0;i<m;i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal){
                return true;
            }

        }
        return false;
    }
};