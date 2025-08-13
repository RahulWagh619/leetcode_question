// Last updated: 8/13/2025, 3:34:17 PM
class Solution {
public:
int dp[302][302];
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        memset(dp,0,sizeof dp);
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
        }
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int mini=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
               if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        // int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=dp[i][j];
            }
        }
        return count;
    }
};