class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(auto it: arr){
            mp[it]++;
        }

        int count = -1;

        for(auto x: mp){
            if( x.first == x.second){
                count = max(count,x.first);
            }
        }
        
        
        return count;
    }
};