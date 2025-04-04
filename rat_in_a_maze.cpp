#include<iostream>
#include<vector>
using namespace std;

    int ans;
    bool CanWeGo(int n,int i,int j,vector<vector<int> >grid){
        return i>=0 && j>=0 && i<n && j<n && grid[i][j]==0;
    }
    void fn(vector<vector<int> >&grid,int n,int i,int j){
        if(i==n-1 && j==n-1){
            ans+=1;
            return;
        }
        grid[i][j]=2;   //2 means visited
        
        //left
        if(CanWeGo(n,i,j-1,grid)){
            fn(grid,n,i,j-1);
        }
        //up
        if(CanWeGo(n,i-1,j,grid)){
            fn(grid,n,i-1,j);
        }
        //right
        if(CanWeGo(n,i,j+1,grid)){
            fn(grid,n,i,j+1);
        }
        //down
        if(CanWeGo(n,i+1,j,grid)){
            fn(grid,n,i+1,j);
        }
        grid[i][j]=0;
    }
    int RatInMaze(vector<vector<int> >&grid,int n){
        ans=0;
        fn(grid,n,0,0);
        return ans;
    }
int main()
{
    vector<vector<int> > grid={
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    cout<<RatInMaze(grid,7);
    return 0;
}