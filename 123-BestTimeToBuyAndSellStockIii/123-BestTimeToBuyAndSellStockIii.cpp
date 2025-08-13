// Last updated: 8/13/2025, 3:36:41 PM
class Solution {
public:
long long dp[100005][4];
int helper(vector<int>& prices,int i,int count){
    if(i==prices.size()||count==4){
        return 0;
    }
    int profit=0;
    if(dp[i][count]!=-1)return dp[i][count];
    if(count%2==0){
        profit=max(-prices[i]+helper(prices,i+1,count+1),helper(prices,i+1,count));
    }
    else{
        profit=max(prices[i]+helper(prices,i+1,count+1),helper(prices,i+1,count));
    }
    return dp[i][count]=profit;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return helper(prices,0,0);
    }
};