class Solution {
public:

    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int>st;
        int maxArea = 0;
        
        arr.push_back(0);
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top();
                st.pop();
                
                int height = arr[element];
                
                int nse= i; //currrent index
                int pse = st.empty()? -1 : st.top(); //pse
                int width = nse-pse-1;
                
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n,0);
        int maxRectangle = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxRectangle = max(maxRectangle, getMaxArea(heights));
        }
        return maxRectangle;
    }
};