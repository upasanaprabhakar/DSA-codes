class Solution {
    public:
        string repeatLimitedString(string s, int repeatLimit) {
            unordered_map<char,int>mp;
            for(int i=0;i<s.size();i++){
                mp[s[i]]++;
            }
            priority_queue<pair<char,int>>pq;
            for(auto p:mp){
                pq.push({p.first,p.second});
            }
            string result="";
            while(!pq.empty()){
                auto largest=pq.top();
                pq.pop();
                int len=min(repeatLimit,largest.second);
                for(int i=0;i<len;i++){
                    result+=largest.first;
                }
                pair<int,char>secondLargest;
                if(largest.second-len>0){
                    if(!pq.empty()){
                        auto secondLargest=pq.top();
                        pq.pop();
                        result+=secondLargest.first;
                        if(secondLargest.second-1>0) pq.push({secondLargest.first,secondLargest.second-1});
                    pq.push({largest.first,largest.second-len});
                    }
                    else{
                        return result;
                    }
                }
            }
        return result;
        }
    };