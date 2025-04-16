class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int,int> mp;
            vector<int>res;
            for(int num: nums1){
                mp[num]++;
            }
            for(int num: nums2){
                if(mp[num]>0){
                    res.push_back(num);
                    mp[num]--;
                }
            }
            return res;
        }
    };