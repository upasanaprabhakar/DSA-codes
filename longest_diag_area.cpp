class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n= dimensions.size();
        int maxArea = 0;
        int maxDia = 0;

        for(int i=0;i<n;i++){
            int l = dimensions[i][0];
            int w= dimensions[i][1];
            int currDia = l*l + w*w;

            if(currDia > maxDia || (currDia == maxDia && l*w > maxArea)){
                maxDia = currDia;
                maxArea = l*w;
            }
        }
        return maxArea;
    }
};