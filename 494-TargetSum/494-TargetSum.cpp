// Last updated: 8/13/2025, 3:35:21 PM
class Solution
{
public:
    // int dp[22][1002];
    // int helper(vector<int> &nums, int i, int sum)
    // {
    //     if (i == nums.size())
    //     {
    //         return sum == 0 ? 1 : 0;
    //     }
    //     if (dp[i][sum] != -1)
    //         return dp[i][sum];
    // }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // memset(dp, 0, sizeof dp);
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total - target) < 0 || (total - target) % 2 != 0)
            return 0;

        int sum = (total - target) / 2;
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        int n = nums.size();
        prev[0] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int val = 0; val <= sum; val++)
            {
                int pick = 0;
                if (nums[i] <= val)
                {
                    pick = prev[val - nums[i]];
                }
                int notpick = prev[val];

               curr[val] = pick + notpick;
            }
            prev=curr;
        }
        return prev[sum];
    }
};