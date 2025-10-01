class Solution {
public:
void bfs(int x,int y,int n,int m,vector<vector<char>>& grid,vector<int>&vis){
        queue<pair<int,int>>q;
        vis[x*m+y]=1;
        q.push({x,y});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
              if(i-1>=0 && vis[((i-1)*m)+j]==0 && grid[i-1][j]=='1'){
                q.push({i-1,j});
                vis[((i-1)*m)+j]=1;
              }
              if(j-1>=0 && vis[(i*m)+j-1]==0 && grid[i][j-1]=='1'){
                q.push({i,j-1});
                vis[(i*m)+j-1]=1;
              }
              if(i+1<n && vis[((i+1)*m)+j]==0 && grid[i+1][j]=='1'){
                q.push({i+1,j});
                vis[((i+1)*m)+j]=1;
              }
              if(j+1<m && vis[(i*m)+j+1]==0 && grid[i][j+1]=='1'){
                q.push({i,j+1});
                vis[(i*m)+j+1]=1;
              }
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
                     bfs(i,j,n,m,grid,vis);
                     count++;
                }
            }
        }
        return count;
    }
};