// Last updated: 8/13/2025, 3:37:36 PM
class Solution {
public:
int dp[10005];
    int jump(vector<int>& nums) {
        memset(dp,0,sizeof dp);
        //  return helper(nums,0);
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
             int pick=1e9;
    for(int j=1;j<=nums[i];j++){
        if(i+j<nums.size()){
        pick=min(pick,dp[i+j]+1);
        }
     }
     dp[i]=pick;
        }
        return dp[0];
    }
};