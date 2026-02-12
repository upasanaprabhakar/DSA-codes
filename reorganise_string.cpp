class Solution {
public:
    string reorganizeString(string s) {
        //count freq
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        //max heap
        priority_queue<pair<int, char>> pq;   //storage -> {freq, char}
        for(auto &it : mp){
            pq.push({it.second, it.first}); 
        }

        string result = "";
        //stores prev used char
        pair<int,char> prev = {0, '#'};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int count = curr.first;
            char ch = curr.second;

            //add curr char to result
            result += ch;
            count--;

            //if prev char still has remaining count -> push it back to heap
            if(prev.first > 0){
                pq.push(prev);
            }

            prev = {count, ch};
        }
        if(result.length() != s.length()){
            return "";
        }
        return result;
    }
};