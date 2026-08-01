class Solution {
public:
int dp[25][25][2];
int helper(vector<int>&nums,int l,int r,int turn){
    if(l>r){
        return 0;
    }
    if(dp[l][r][turn]!=-1)return dp[l][r][turn];
    if(!turn){
        return max(helper(nums,l+1,r,1)+nums[l],helper(nums,l,r-1,1)+nums[r]);
    }
    return dp[l][r][turn]=min(helper(nums,l+1,r,0),helper(nums,l,r-1,0));
}
    bool predictTheWinner(vector<int>& nums) {
         memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int val=helper(nums,0,n-1,0);
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }
        if(val*2>=sum){
            return true;
        }
        return false;

    }
};