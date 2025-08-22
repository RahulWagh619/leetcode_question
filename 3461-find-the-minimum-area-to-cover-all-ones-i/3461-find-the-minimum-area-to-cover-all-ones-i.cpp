class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top=-1;
        int bottom=-1;
        int left=-1;
        int right=-1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    top=i;
                    break;
                }
            }
            if(top!=-1){
                break;
            }
        }
        cout<<top<<endl;
        if(top==-1){
            return 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    bottom=i;
                    break;
                }
            }
             if(bottom!=-1){
                break;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    left=j;
                    break;
                }
            }
             if(left!=-1){
                break;
            }
        }
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    right=j;
                    break;
                }
            }
             if(right!=-1){
                break;
            }
        }
        int width=(right-left+1);
        int height=(bottom-top+1);
        return width*height;
    }
};