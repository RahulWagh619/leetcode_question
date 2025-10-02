class Solution {
public:
void dfs(vector<vector<int>>& image, int sr, int sc, int color,vector<int>&vis,int val){
        int n=image.size();
        int m=image[0].size();
        int x=sr;
        int y=sc;
        image[x][y]=color;
        vis[(x*m)+y]=1;
            if(x-1>=0 && image[x-1][y]==val && vis[(x-1)*m+y]==0){
                dfs(image,x-1,y,color,vis,val);
            }
            if(x+1<n && image[x+1][y]==val && vis[(x+1)*m+y]==0){
                dfs(image,x+1,y,color,vis,val);
            }
            if(y-1>=0 && image[x][y-1]==val && vis[(x)*m+y-1]==0){
                 dfs(image,x,y-1,color,vis,val);

            }
            if(y+1<m && image[x][y+1]==val && vis[(x)*m+y+1]==0){
                dfs(image,x,y+1,color,vis,val);
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