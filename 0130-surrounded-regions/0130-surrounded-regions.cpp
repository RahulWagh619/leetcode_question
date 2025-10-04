class Solution {
public:
void dfs(int x,int y,vector<vector<char>>& board, vector<int>&vis){
      int n=board.size();
      int m=board[0].size();
      int dr[]={0,0,-1,1};
      int dc[]={1,-1,0,0};
      vis[x*m+y]=1;
      board[x][y]='1';
       for(int i=0;i<4;i++){
                int row=x+dr[i];
                int col=y+dc[i];
                int index=row*m+col;
                if(row>=0 && row<n && col>=0 && col<m){
                    if(vis[index]==1||board[row][col]=='X'){
                        continue;
                    }
                    // board[row][col]='1';
                    dfs(row,col,board,vis);
                }
            }

}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int>vis(n*m,0);
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i*m]==0){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O'  && vis[i*m+(m-1)]==0){
                dfs(i,m-1,board,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && vis[j]==0){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j]=='O' && vis[(n-1)*m+j]==0){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};