// Last updated: 8/13/2025, 3:36:17 PM
class Solution {
public:
// int dp[1005][3][102];
// int helper(vector<int>& prices,int i,int buy,int count,int k){
//     if(i==prices.size()||count==k){
//         return 0;
//     }
//     if(dp[i][buy][count]!=-1)return dp[i][buy][count];
//     int profit=0;
//     if(buy){
//         profit=max(-prices[i]+helper(prices,i+1,0,count,k),helper(prices,i+1,1,count,k));

//     }
//     else{
//         profit=max(prices[i]+helper(prices,i+1,1,count+1,k),helper(prices,i+1,0,count,k));
//     }
//     return dp[i][buy][count]=profit;
// }
    int maxProfit(int k, vector<int>& prices) {
        // memset(dp,0,sizeof dp);
        // return helper(prices,0,1,0,k);
        int n=prices.size();
         vector<vector<long long>>prev(2,vector<long long>(k+1));
        vector<vector<long long>>curr(2,vector<long long>(k+1));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                for (int count =0; count<k; count++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[i] + prev[0][count], prev[1][count]);
                    }
                    else
                    {
                        profit = max(prices[i] + prev[1][count+1], prev[0][count]);
                    }
                     curr[buy][count] = profit;
                }
            }
            prev=curr;
        }
        return prev[1][0];
    }
};