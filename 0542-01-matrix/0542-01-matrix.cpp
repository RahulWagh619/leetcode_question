class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>vis(n*m,0);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[(i*m)+j]=1;
                    q.push({i,j});
                }
            }
        }
        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};
        int count=1;
        while(!q.empty()){
             int size=q.size();
             for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int row=x+dr[k];
                    int col=y+dc[k];
                    int index=row*m+col;
                    if(row>=0 && row<n && col>=0 && col<m){
                        if(vis[index]==1){
                            continue;
                        }
                        vis[index]=1;
                        q.push({row,col});
                        if(mat[row][col]==1){
                              mat[row][col]=count;
                        }
                        
                    }
                }
             }
             count++;
        }
        return mat;
    }
};