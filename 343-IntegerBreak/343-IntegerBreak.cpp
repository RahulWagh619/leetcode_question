// Last updated: 8/13/2025, 3:35:35 PM
class Solution {
public:

int dp[60];
// int helper(int n){
//     if(n==1){
//         return 1;
//     }
//     if(dp[n]!=-1)return dp[n];
    
// }
    int integerBreak(int n) {
        memset(dp,0,sizeof dp);
        dp[1]=1;
        for(int N=2;N<=n;N++){
            int maxi=0;
    for(int i=1;i<=N-1;i++){
         int product = max(i * (N - i), i * dp[N - i]); 
            maxi = max(maxi, product);
    }
     dp[N]=maxi;

        }
        return dp[n];
    }
};