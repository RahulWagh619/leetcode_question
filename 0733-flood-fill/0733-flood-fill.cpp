class Solution {
public:
void bfs(vector<vector<int>>& image, int sr, int sc, int color,vector<int>&vis){
        int n=image.size();
        int m=image[0].size();
        int val=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int x=sr;
        int y=sc;
        image[x][y]=color;
        vis[(x*m)+y]=1;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            if(x-1>=0 && image[x-1][y]==val && vis[(x-1)*m+y]==0){
                image[x-1][y]=color;
                vis[(x-1)*m+y]=1;
                q.push({x-1,y});
            }
            if(x+1<n && image[x+1][y]==val && vis[(x+1)*m+y]==0){
                image[x+1][y]=color;
                vis[(x+1)*m+y]=1;
                q.push({x+1,y});

            }
            if(y-1>=0 && image[x][y-1]==val && vis[(x)*m+y-1]==0){
                image[x][y-1]=color;
                vis[(x)*m+y-1]=1;
                q.push({x,y-1});

            }
            if(y+1<m && image[x][y+1]==val && vis[(x)*m+y+1]==0){
                image[x][y+1]=color;
                vis[(x)*m+y+1]=1;
                q.push({x,y+1});
            }
        }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<int>vis((n*m)+1,0);
        bfs(image,sr,sc,color,vis);
        return image;
    }
};