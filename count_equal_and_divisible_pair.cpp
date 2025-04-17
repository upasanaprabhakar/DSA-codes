class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,unordered_map<int,int>>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int mi= i % k;
            if(mp.count(nums[i])){
                for(auto& [mj,cnt] :mp[nums[i]]){
                    if(mi*mj % k == 0){
                        ans+=cnt;
                    }
                }
                
            }
            mp[nums[i]][mi]++;
        }
        
        return ans;

    }
};