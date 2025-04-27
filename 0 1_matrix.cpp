class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            if(mat.empty() || mat[0].empty()){
                return {};
            }
            int n= mat.size();
            int m= mat[0].size();
            queue<pair<int,int> >q;
            int max_val= m*n;
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j] == 0){
                        q.push({i,j});
                    }
                    if(mat[i][j] == 1){
                        mat[i][j]= max_val;
                    }
                }
            }
    
            vector<vector<int> >dir= {{1,0},{-1,0},{0,1},{0,-1}};
            while(!q.empty()){
                auto cell= q.front(); q.pop();
                int i= cell.first;
                int j= cell.second;
    
                for(int d=0;d<4;d++){
                    int nr= i+dir[d][0];
                    int nc= j+dir[d][1];
    
                    if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                    if(mat[nr][nc] > mat[i][j]+1){
                        mat[nr][nc]= mat[i][j]+1;
                        q.push({nr,nc});
                    }
                }
               
            }
            return mat;
        }
        
    };