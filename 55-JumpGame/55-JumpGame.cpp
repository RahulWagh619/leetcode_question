// Last updated: 8/13/2025, 3:37:28 PM
class Solution
{
public:
    int dp[10005];
    // bool helper(vector<int> &nums, int i)
    // {
    //     if (i >= nums.size() - 1)
    //         return 1;
    //     if (nums[i] == 0)
    //         return false;
        
    // }
    bool canJump(vector<int> &nums)
    {
        memset(dp, 0, sizeof dp);
        int n=nums.size();
        dp[n-1]=1;
        // return helper(nums, 0);
        for(int i=n-2;i>=0;i--){
            for (int j = 1; j <= nums[i]; j++)
        {
            if (i + j < nums.size() && dp[i + j])
            {
                dp[i] = true;
                break;
            }
         }
        }
        return dp[0];
    }
};