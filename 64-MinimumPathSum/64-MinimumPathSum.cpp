// Last updated: 8/13/2025, 3:37:21 PM
class Solution {
public:

// int dp[202][202];
    // int helper(vector<vector<int>>& grid, int i, int j) {
    //     if (i ==0 && j ==0) return grid[i][j];
    //     if (i<0 || j<0) return 1e9;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int left = helper(grid, i, j - 1) + grid[i][j];
    //     int up = helper(grid, i - 1, j) + grid[i][j];

    //     return dp[i][j]= min(left, up);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        // memset(dp,-1,sizeof dp);
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dp(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[0]=grid[i][j];
                continue;
            }
            int up=1e9,left=1e9;
            if(j-1>=0){
             left=temp[j-1]+grid[i][j];
            }
            if(i-1>=0){
              up=dp[j]+grid[i][j];
            }
            temp[j]=min(left,up);
          }
          dp=temp;
        }
        return dp[m-1];
    }
};
