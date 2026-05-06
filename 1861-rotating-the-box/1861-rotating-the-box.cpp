class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>>grid(m,vector<char>(n));
       for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        grid[j][n - 1 - i] = boxGrid[i][j];
    }
}
        for(int j=0;j<n;j++){
          queue<pair<int,int>>q;
            for(int i=m-1;i>=0;i--){
                if(grid[i][j]=='*'){
                    while(!q.empty()) q.pop();
                }
                else if(grid[i][j]=='.'){
                    q.push({i,j});
                }
               else{
                    if(q.empty()){
                        continue;
                    }
                    else{
                      int posx=q.front().first;
                      int posy=q.front().second;
                      grid[posx][posy]=grid[i][j];
                      q.pop();
                      q.push({i,j});
                      grid[i][j]='.';
                    }
                }

            }
        }
        return grid;
    }
};