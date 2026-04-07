class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        
        for(int a = 1; a*a*a <= n; a++){
            for(int b = a; a*a*a + b*b*b <= n; b++){
                int sum = a*a*a + b*b*b;
                mp[sum]++;
            }
        }

        vector<int> ans;
        for(auto &it : mp){
            if(it.second >= 2){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
    
};