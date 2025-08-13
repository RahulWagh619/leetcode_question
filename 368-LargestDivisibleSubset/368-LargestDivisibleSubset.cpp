// Last updated: 8/13/2025, 3:35:32 PM
class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> helper(vector<int>& nums, int i, int k) {
        if (i == nums.size()) return {};

        if (!dp[i][k + 1].empty()) return dp[i][k + 1];

        vector<int> pick, notpick;

        if (k == -1 || nums[i] % nums[k] == 0) {
            pick = helper(nums, i + 1, i);
            pick.insert(pick.begin(), nums[i]);
        }

        notpick = helper(nums, i + 1, k);

        if (pick.size() > notpick.size()) {
            return dp[i][k + 1] = pick;
        }
        return dp[i][k + 1] = notpick;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n + 1));  // dp[i][k+1]
        return helper(nums, 0, -1);
    }
};
