class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> used;

        pq.push(1);
        used.insert(1);

        long curr = 1;

        for(int i=0;i<n;i++){
            curr = pq.top();
            pq.pop();

            long a = curr*2;
            long b = curr*3;
            long c = curr*5;

            if(!used.count(a)){
                pq.push(a);
                used.insert(a);
            }

            if(!used.count(b)){
                pq.push(b);
                used.insert(b);
            }

            if(!used.count(c)){
                pq.push(c);
                used.insert(c);
            }
        }
        return curr;
    }
};