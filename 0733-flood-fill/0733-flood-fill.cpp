class Solution {
public:
void dfs(vector<vector<int>>& image, int sr, int sc, int color,vector<int>&vis,int val){
        int n=image.size();
        int m=image[0].size();
        int x=sr;
        int y=sc;
        image[x][y]=color;
        vis[(x*m)+y]=1;
        int dr[4] = { -1, +1,  0,  0 };
        int dc[4] = {  0,  0, -1, +1 };
        for(int i=0;i<4;i++){
            int nx = x + dr[i];
            int ny = y + dc[i];
            int idx = nx * m + ny;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !vis[idx]
                && image[nx][ny] == val) {
                dfs(image, nx, ny, color, vis, val);
            }
        }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<int>vis((n*m)+1,0);
        int val=image[sr][sc];
        dfs(image,sr,sc,color,vis,val);
        return image;
    }
};