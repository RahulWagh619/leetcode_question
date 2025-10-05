class Solution {
public:
void bfs(int x,int y,vector<vector<int>>& heights,vector<int>&vis){
    int n=heights.size();
    int m=heights[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x*m+y]=1;
    int dr[]={0,0,-1,1};
    int dc[]={-1,1,0,0};
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
    for(int i=0;i<4;i++){
        int row=x+dr[i];
        int col=y+dc[i];
        int index=row*m+col;
        if(row>=0 && col>=0 && row<n && col<m){
            if(!vis[row * m + col]&& heights[row][col]>=heights[x][y]){
                vis[row*m+col]=1;
               q.push({row,col});
            }
        }
      }

    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<int>visa(n*m,0);
        vector<int>visp(n*m,0);
        for(int i=0;i<n;i++){
            bfs(i,0,heights,visp);
        }
        for(int j=1;j<m;j++){
            bfs(0,j,heights,visp);
        }
        for(int j=0;j<m;j++){
            bfs(n-1,j,heights,visa);
        }
        for(int i=0;i<n-1;i++){
            bfs(i,m-1,heights,visa);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visa[i*m+j] && visp[i*m+j]){
                   ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};