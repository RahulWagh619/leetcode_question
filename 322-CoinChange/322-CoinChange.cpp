// Last updated: 8/13/2025, 3:35:38 PM
class Solution
{
public:
    // int dp[13][10003];
    // int helper(vector<int> &coins, int i, int amount)
    // {
    //     if (amount == 0)
    //     {
    //         return 0;
    //     }
    //     if (i == coins.size())
    //         return 1e9;
    //     if (dp[i][amount] != -1)
    //         return dp[i][amount];
    // }
    int coinChange(vector<int> &coins, int amount)
    {
        // memset(dp, 0, sizeof dp);
        int n=coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        for (int val = 0; val <= amount; val++)
        {
            prev[val] = 1e9;
        }
        for (int i = 0; i <= n; i++) {
            prev[0] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int val = 0; val <=amount; val++)
            {
                int pick = 1e9;
                if (coins[i] <= val)
                {
                    pick = 1 + curr[val - coins[i]];
                }
                int notpick = 0 + prev[val];
                curr[val] = min(pick, notpick);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return (ans >= 1e9 ? -1 : ans);
    }
};