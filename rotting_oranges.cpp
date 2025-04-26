class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int,int> >q;  // Queue for multi-source BFS
            int fo= 0;  
            int n= grid.size();
            int m= grid[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]== 1) fo++;
                    else if(grid[i][j]== 2) q.push({i,j});  // Add initial rotten oranges
                }
            }
            q.push({-1,-1});  // Delimiter to mark 1 minute completion
            int mins= 0;
            vector<vector<int> > dir= {{-1,0},{1,0},{0,-1},{0,1}};  
            while(!q.empty()){
                auto cell =q.front();
                q.pop();
                if(cell.first == -1 and cell.second == -1){
                    mins++;  // One minute passed
                    if(!q.empty()){
                        q.push({-1,-1});
                    }
                    else{
                        break;
                    }
                }
                else{
                    int i= cell.first;
                    int j= cell.second;
                    for(int d=0;d<4;d++){
                        int nr= i+dir[d][0];
                        int nc= j+dir[d][1];
                        if(nr<0 || nc<0 || nr>=n || nc>=m) continue;  
                        if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;  
                        fo--;  // Fresh orange becomes rotten
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            return (fo == 0)? mins-1 : -1;  
        }
    };
    