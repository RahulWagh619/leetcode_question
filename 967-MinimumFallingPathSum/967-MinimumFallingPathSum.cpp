// Last updated: 8/13/2025, 3:34:38 PM
class Solution {
public:

// int dp[102][102];
// int helper(vector<vector<int>>& matrix,int i,int j,int n,int m){
//     if(i==n-1){
//         return matrix[i][j];
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     int down=1e9,left=1e9,right=1e9;
//     down=helper(matrix,i+1,j,n,m)+matrix[i][j];
//     if(j-1>=0){
//         left=helper(matrix,i+1,j-1,n,m)+matrix[i][j];
//     }
//     if(j+1<=m-1){
//         right=helper(matrix,i+1,j+1,n,m)+matrix[i][j];
//     }
//     return dp[i][j]=min({down,right,left});

// }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int mini=INT_MAX;
        vector<int>prev(n,0);
        for(int j=0;j<n;j++){
          prev[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n,0);
            for(int j=n-1;j>=0;j--){
                 int up=1e9,left=1e9,right=1e9;
                 if(j-1>=0){
                    left=prev[j-1]+matrix[i][j];
                 }
                 if(j+1<n){
                    right=prev[j+1]+matrix[i][j];
                 }
                 up=prev[j]+matrix[i][j];
              temp[j]=min({up,left,right});
            }
            prev=temp;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int k=prev[i];
            mini=min(mini,k);
        }
        return mini;
    }
};