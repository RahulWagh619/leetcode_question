// Last updated: 8/13/2025, 3:34:59 PM
class Solution
{
public:
    // int dp[50002][3];
    // int helper(vector<int> &prices, int i, int buy, int fee)
    // {
    //     if (i == prices.size())
    //         return 0;
    //     if (dp[i][buy] != -1)
    //         return dp[i][buy];
    // }
    int maxProfit(vector<int> &prices, int fee)
    {
        // memset(dp, 0, sizeof dp);
        int n=prices.size();
        vector<int>prev(3,0);
        vector<int>curr(3,0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[i] - fee + prev[1], prev[0]);
                }
            curr[buy] = profit;
            }
            prev=curr;
        }
        return prev[1];

        // return helper(prices,0,1,fee);
    }
};