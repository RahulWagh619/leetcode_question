// Last updated: 8/13/2025, 3:35:26 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        int n = nums.size();

        // dp[i][j]: can we make sum j using elements from i to n
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int t = 0; t <= target; t++) {
                bool notPick = dp[i + 1][t];
                bool pick = false;
                if (t - nums[i] >= 0)
                    pick = dp[i + 1][t - nums[i]];

                dp[i][t] = pick || notPick;
            }
        }

        return dp[0][target];
    }
};
