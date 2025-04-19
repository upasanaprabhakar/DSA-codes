class Solution {
    public:
        void dfs(vector<vector<int> > &image, int currRow, int currColumn, int initialColor, int newColor){
            int n=image.size();
            int m=image[0].size();
            if(currRow<0 || currColumn<0 || currRow>=n || currColumn>=m){
                return;     //outside the grid
            }
            //if the curr cell color is not as initial color
            if(image[currRow][currColumn]!= initialColor) return;
    
            image[currRow][currColumn]=newColor;
            dfs(image,currRow+1, currColumn, initialColor, newColor);   //down
            dfs(image,currRow, currColumn-1, initialColor, newColor);   //left
            dfs(image,currRow-1, currColumn, initialColor, newColor);   //up
            dfs(image,currRow, currColumn+1, initialColor, newColor);   //right
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            if(color == image[sr][sc]) return image;
            dfs(image,sr,sc,image[sr][sc],color);
            return image;
        }
    };