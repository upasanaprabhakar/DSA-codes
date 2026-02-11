class Solution {
public:
    typedef pair<int,pair<int,int>> piv;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<piv, vector<piv>, greater<piv>> pq;

        int currMax = INT_MIN;
        int n = nums.size();

        //push first ele of each list
        for(int i=0;i<n;i++){
            int value = nums[i][0];
            pq.push({value,{i,0}});
            currMax = max(currMax, value);
        }

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        //process heap
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currMin = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            //update best range
            if(currMax-currMin < rangeEnd-rangeStart){
                rangeEnd = currMax;
                rangeStart = currMin;
            } 
            
            //move forward in same list
            if(c+1 < nums[r].size()){
                int nextVal = nums[r][c+1];
                pq.push({nextVal, {r,c+1}});
                currMax = max(currMax, nextVal);
            }
            else{ //one list ends
                break;
            }
        }
        return {rangeStart, rangeEnd};
    }
};