class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char,int>mp;
            for(auto x:s){
                mp[x]++;
            }
            priority_queue<pair<int,char>>pq;
            for(auto ele:mp){
                pq.push({ele.second,ele.first});
            }
            string ans;
            while(pq.size()>0){
                int freq=pq.top().first;
                char ch=pq.top().second;
                pq.pop();
                for(int i=0;i<freq;i++){
                    ans.push_back(ch);
                }
            }
            return ans;
        }
    };