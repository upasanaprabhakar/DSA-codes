class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
            int sum=0;
            for(int i:nums)sum+=i;
            while(k--){
                int ele=pq.top();//min ele
                if(ele==0){
                    break;
                }
                pq.pop();//remove the smallest ele
                sum-=ele;
                pq.push(-1*ele);//add the smallest ele
                sum+=(-ele);
    
            }
            return sum;
        }
    };