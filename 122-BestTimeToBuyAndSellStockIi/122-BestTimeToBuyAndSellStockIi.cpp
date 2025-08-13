// Last updated: 8/13/2025, 3:36:43 PM
class Solution
{
public:
    // long long dp[30005][2];
    // int helper(vector<int> &prices, int i, int buy)
    // {
    //     if (i == prices.size())
    //         return 0;
    //     if (dp[i][buy] != -1)
    //         return dp[i][buy];
    // }
    int maxProfit(vector<int> &prices)
    {
        // memset(dp, 0, sizeof dp);
        // return helper(prices,0,1);

        int n = prices.size();
        vector<long long>prev(2,0);
        vector<long long>curr(2,0);
        prev[0] = 0;
        prev[1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                long long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[i] + prev[1], prev[0]);
                }
             curr[buy] = profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};