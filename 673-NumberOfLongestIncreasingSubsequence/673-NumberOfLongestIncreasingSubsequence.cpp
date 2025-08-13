// Last updated: 8/13/2025, 3:35:03 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        vector<int>count(n+1,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                   if(dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    count[i]=count[prev];
                   }
                   else if (dp[prev] + 1 == dp[i]) {
    count[i] += count[prev];
}
                }
            maxi=max(maxi,dp[i]);
            }
        }
        // return maxi;
        int total=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                total+=count[i];
            }
        }
        return total;
    }
};