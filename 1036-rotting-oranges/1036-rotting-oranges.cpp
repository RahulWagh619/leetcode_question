class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>vis(n*m+1,0);
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
         int dr[]={0,0,-1,1};
    int dc[]={-1,1,0,0};
    while(!q.empty()){
        int size=q.size();
        bool got=false;
        for(int z=0;z<size;z++){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
    for(int i=0;i<4;i++){
         int row=x+dr[i];
         int col=y+dc[i];
         int index=row*m+col;
         if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[index]==0){
            grid[row][col]=2;
            q.push({row,col});
            vis[index]=1;
            got=true;
         }

        }
    }
         if(got){
            count++;
         }
    }
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    found=true;
                    break;
                }
            }
        }
        if(found){
            return -1;
        }
        return count;
    }
};