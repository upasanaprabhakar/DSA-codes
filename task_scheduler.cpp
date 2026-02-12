class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count frequency
        unordered_map<char, int> mp;
        for (char ch : tasks) {
            mp[ch]++;
        }

        // create heap
        priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }

        // cooldown queue storage -> {remainingFreq, timeAvailable}
        queue<pair<int, int>> cooldown;
        long long time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            // execute a task
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();

                freq--;

                if (freq > 0) {
                    cooldown.push({freq, time + n});
                }
            }

            // if cooldown finishes then push back to heap
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};