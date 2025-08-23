class Solution {
public:
int dp[21];
int helper(int n){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1)return dp[n];
    int value=0;
    for(int i=1;i<=n;i++){
        int left=helper(i-1);
        int right=helper(abs(n-i));
        value+=left*right;
    }
    return dp[n]=value;
}
    int numTrees(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
    }
};