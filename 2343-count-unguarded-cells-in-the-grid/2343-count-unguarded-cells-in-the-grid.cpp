class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,1));
        for(int i=0;i<walls.size();i++){
              int x=walls[i][0];
              int y=walls[i][1];
              grid[x][y]=0;
        }
         for(int i=0;i<guards.size();i++){
              int x=guards[i][0];
              int y=guards[i][1];
              grid[x][y]=0;
        }
        for(int z=0;z<guards.size();z++){
              int x=guards[z][0];
              int y=guards[z][1];
              int i=x;
              i--;
              while(i>=0 && (grid[i][y]==1||grid[i][y]==2)){
                  grid[i][y]=2;
                  i--;
              }
              i=x;
              i++;
            while(i<m && (grid[i][y]==1||grid[i][y]==2)){
                  grid[i][y]=2;
                  i++;
              }
              int j=y;
              j--;
               while(j>=0 && (grid[x][j]==1||grid[x][j]==2)){
                  grid[x][j]=2;
                j--;
              }
              j=y;
              j++;
            while(j<n && (grid[x][j]==1||grid[x][j]==2)){
                  grid[x][j]=2;
                j++;
              }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};