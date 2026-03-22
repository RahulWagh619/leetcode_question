class Solution {
public:
int dp[42][100003];
int helper(vector<int>& nums, int target,int i,int xorr){
    int n=nums.size();
       if(i == n) {
            if(xorr == target) return 0;
            return -1e9;
        }
    if(dp[i][xorr]!=-1)return dp[i][xorr];

    int pick=helper(nums,target,i+1,xorr ^ nums[i])+1;
    int notpick=helper(nums,target,i+1,xorr);
    return dp[i][xorr]=max(pick,notpick);
}
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int v=helper(nums,target,0,0);
        if(v<0)return -1;
        return n-v;
    }
};