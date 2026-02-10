class Solution {
public:
    struct Compare{
        bool operator() (const pair<string,int>&a, const pair<string,int>&b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto x: words){
            mp[x]++;
        }

        priority_queue<pair<string,int>, vector<pair<string,int>>, Compare> minHeap;

        for(auto it : mp){
            minHeap.push({it.first, it.second});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<string> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};