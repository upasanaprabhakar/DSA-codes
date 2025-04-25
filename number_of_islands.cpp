class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int rows= grid.size();
            int cols= grid[0].size();
            int cc=0; //no of connected components
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    if(grid[r][c] == '0'){
                        //it is a water body
                        continue;
                    }
                    //new unvisited land piece
                    cc++;
                    grid[r][c] = '0';   //mark it visited
                    queue<pair<int,int> > q;
                    q.push({r,c});      //store the src node
                    while(!q.empty()){
                        auto curr = q.front();     //get one node from queue
                        q.pop();
                        //go to all unvisited neighbours of the curr node
                        int currRow = curr.first;
                        int currCol = curr.second;
    
                        //check up
                        if(currRow-1>=0 && grid[currRow-1][currCol] == '1'){
                            q.push({currRow-1,currCol});
                            grid[currRow-1][currCol] = '0';
                        }
                        //check down
                        if(currRow+1<rows && grid[currRow+1][currCol] == '1'){
                            q.push({currRow+1,currCol});
                            grid[currRow+1][currCol] = '0';
                        }
                        //check left
                        if(currCol-1>=0 && grid[currRow][currCol-1] == '1'){
                            q.push({currRow,currCol-1});
                            grid[currRow][currCol-1] = '0';
                        }
                        //check right
                        if(currCol+1<cols && grid[currRow][currCol+1] == '1'){
                            q.push({currRow,currCol+1});
                            grid[currRow][currCol+1] = '0';
                        }
                    }
    
                }
            }
            return cc;
        }
    };