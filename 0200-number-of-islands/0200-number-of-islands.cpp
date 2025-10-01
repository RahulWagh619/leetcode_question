class Solution {
public:
void dfs(int x,int y,int n,int m,vector<vector<char>>& grid,vector<int>&vis){
        vis[x*m+y]=1;
        int i=x;
        int j=y;
              if(i-1>=0 && vis[((i-1)*m)+j]==0 && grid[i-1][j]=='1'){
               dfs(i-1,j,n,m,grid,vis);
              }
              if(j-1>=0 && vis[(i*m)+j-1]==0 && grid[i][j-1]=='1'){
                 dfs(i,j-1,n,m,grid,vis);
              }
              if(i+1<n && vis[((i+1)*m)+j]==0 && grid[i+1][j]=='1'){
                 dfs(i+1,j,n,m,grid,vis);
              }
              if(j+1<m && vis[(i*m)+j+1]==0 && grid[i][j+1]=='1'){
                dfs(i,j+1,n,m,grid,vis);
              }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>vis((n*m)+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int index=i*m+j;
                if(vis[index]==0 && grid[i][j]=='1'){
                     dfs(i,j,n,m,grid,vis);
                     count++;
                }
            }
        }
        return count;
    }
};