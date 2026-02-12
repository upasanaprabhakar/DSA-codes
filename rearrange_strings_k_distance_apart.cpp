class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;

        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue <pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        string result = "";
        queue<pair<int,char>> cooldown;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int count = curr.first;
            int ch = curr.second;

            result += ch;
            count --;

            cooldown.push({count,ch});

            if(cooldown.size() == k){
                auto front = cooldown.front();
                cooldown.pop();

                if(front.first > 0){
                    pq.push(front);
                }
            }
        }
        
        if(result.length() != s.length()){
            return "";
        }
        return result;
    }
};
