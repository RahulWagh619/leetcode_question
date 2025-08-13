// Last updated: 8/13/2025, 3:36:07 PM
class Solution {
public:
    int dp[102];

    int helper(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int take = nums[i] + helper(i + 2, nums);
        int skip = helper(i + 1, nums);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> a, b;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) a.push_back(nums[i]);              // 1 to n-1
            if (i != nums.size() - 1) b.push_back(nums[i]); // 0 to n-2
        }

        memset(dp, -1, sizeof dp);
        int val1 = helper(0, a);

        memset(dp, -1, sizeof dp);
        int val2 = helper(0, b);

        return max(val1, val2);
    }
};
