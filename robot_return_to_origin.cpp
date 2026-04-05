class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        
        for(char &ch : moves){
            if(ch == 'U') y++;
            else if(ch == 'D') y--;
            else if(ch == 'R') x++;
            else if(ch == 'L') x--;
        }

        if(x==0 && y==0) return true;
        return false;
    }
};