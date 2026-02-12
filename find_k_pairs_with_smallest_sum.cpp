class Solution {
public:
    typedef pair<pair<int,int>, int> ppi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        
        if(nums1.empty() || nums2.empty() || k==0){
            return result;
        }

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        //storage -> {{sum,i}, j}

        //push first ele of each row
        for(int i=0; i<nums1.size() && i<k; i++){
            pq.push({{nums1[i]+nums2[0], i}, 0});
        }

        while(k-- > 0 && !pq.empty()){
            auto top = pq.top();
            pq.pop();

            int sum = top.first.first;
            int i = top.first.second;
            int j = top.second;

            result.push_back({nums1[i], nums2[j]});

            //move right in same row
            if(j+1 < nums2.size()){
                pq.push({{nums1[i]+ nums2[j+1],i}, j+1});
            }
        }
        return result;
    }
};