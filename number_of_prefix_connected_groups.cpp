class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> ans;
        
        for(string &w : words){
            if(w.length() < k) continue;     // ignore short words
            string prefix = w.substr(0,k);
            ans[prefix]++;                   // count this prefix
        }
        
        int groups = 0;
        for(auto &p : ans){
            if(p.second >= 2) groups++;      // valid group
        }
        
        return groups;
    }
};
