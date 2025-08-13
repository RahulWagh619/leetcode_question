// Last updated: 8/13/2025, 3:35:40 PM
class Solution
{
public:
    int dp[302][302];
    // int helper(vector<int> &a, int i, int j)
    // {
    //     if (i > j)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    // }
     int maxCoins(vector<int> &nums)
    {
        vector<int> a;
        a.push_back(1);
        for (int i = 0; i < nums.size(); i++)
        {
            a.push_back(nums[i]);
        }
        a.push_back(1);
        memset(dp, 0, sizeof dp);
        // return helper(a,1,a.size()-2);
        for (int i = nums.size(); i >= 1; i--)
        {
            for (int j = 1; j <= nums.size(); j++)
            {
                if(i>j){
                    continue;
                }
                int maxi = -1e9;
                for (int k = i; k <= j; k++)
                {
                    int cost = a[i - 1] * a[k] * a[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][nums.size()];
    }
};