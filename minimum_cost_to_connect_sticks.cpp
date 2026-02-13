class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        // Min heap 
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push all stick lengths into heap
        for (int len : sticks) {
            pq.push(len);
        }
        
        int totalCost = 0;
        
        // Keep combining until one stick remains
        while (pq.size() > 1) {
            
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            int cost = first + second;
            totalCost += cost;
            
            // Push the combined stick back
            pq.push(cost);
        }
        
        return totalCost;
    }
};
