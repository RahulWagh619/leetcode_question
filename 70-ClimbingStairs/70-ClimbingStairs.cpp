// Last updated: 8/13/2025, 3:37:18 PM
class Solution {
public:
int dp[50];
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
           int curi=prev+prev2;
           prev2=prev;
           prev=curi;
        }
        return prev;
    }
};