class Solution {
    public:
        int numRabbits(vector<int>& ans) {
            unordered_map<int,int>mp;
            int result=0;
            for(int i=0;i<ans.size();i++){
                if(!mp[ans[i]+1]){
                    result+=ans[i]+1;  //we started a new colour group
                    if(ans[i]==0) continue;
                    mp[ans[i]+1]=1;            
                }
                else{
                    mp[ans[i]+1]++;
                    int key=ans[i]+1;
                    int val=mp[key];
                    if(key==val){    //we found all rabbits of the group 
                        mp.erase(key);  //eliminate the group
                    }
                }
            }
            return result;
        }
    };