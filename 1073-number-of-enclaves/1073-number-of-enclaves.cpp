class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<int>vis(n*m,0);
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                q.push({0,j});
            }
            if(grid[n-1][j]==1){
                q.push({n-1,j});
            }
        }
        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            vis[x*m+y]=1;
            grid[x][y]=2;
            for(int i=0;i<4;i++){
                int row=x+dr[i];
                int col=y+dc[i];
                int index=row*m+col;
                if(row>=0 && row<n && col>=0 && col<m){
                    if(vis[index]==1||grid[row][col]==0){
                        continue;
                    }
                    grid[row][col]=2;
                    q.push({row,col});
                    vis[index]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=2 && grid[i][j]==1){
                   count++;
                }
            }
        }
        return count;
    }
};