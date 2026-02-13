class Solution {
public:
    struct CompareInterval {
        bool operator()(const Interval& a, const Interval& b) {
            return a.start < b.start;
        }
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        //sort by start time
        sort(intervals.begin(), intervals.end(), CompareInterval());

        //min heap for end times
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num : intervals){
            //if earliest meet done -> resuse room
            if(!pq.empty() && pq.top() <= num.start){
                pq.pop();
            }

            //allocate room -> push end time
            pq.push(num.end);
        }
        return pq.size();
    }
};
