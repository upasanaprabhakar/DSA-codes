class Solution {
public:
    int countKDifference(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        
        for(int m : arr){
            mp[m]++;
        }
        
        int count = 0;
        
        for(auto it : mp){
            int x = it.first;
            
            if(mp.count(x+k)){
                count += it.second * mp[x+k];
            }
        }
        return count;
    }
};