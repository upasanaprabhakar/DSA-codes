class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(),people.end());
            int i=0;
            int j=people.size()-1;
            int bt=0;
            while(i<=j){
                if(people[i]+people[j]<=limit){
                    bt++;   //allocate boat to a pair
                    i++;
                    j--; 
                }
                else{
                    bt++;   //allocate boat to the heaviest
                    j--;
                }
            }
            return bt;
        }
    };