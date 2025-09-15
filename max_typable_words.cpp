class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count= 0;
        istringstream iss (text);
        string word;

        while(iss >> word){
            bool canType = true;

            for(char w : word){
                for(char b: brokenLetters){
                    if(w == b){
                        canType = false;
                        break;
                    }
                }
                if(!canType) break;
            } 
            if(canType) count++;
        }
        return count;
    }
};