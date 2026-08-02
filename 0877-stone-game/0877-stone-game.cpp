class Solution {
public:
int dp[502][502][2];
int helper(vector<int>&piles,int l,int r,int turn){
    if(l>r){
        return 0;
    }
    if(dp[l][r][turn]!=-1)return dp[l][r][turn];
    if(!turn){
        return max(helper(piles,l+1,r,1)+piles[l],helper(piles,l,r-1,1)+piles[r]);
    }
    return dp[l][r][turn]=max(helper(piles,l+1,r,0),helper(piles,l,r-1,0));
}
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int val=helper(piles,0,n-1,0);
        int sum=0;
        for(auto &i:piles){
            sum+=i;
        }
        sum/=2;
        if(val>sum){
            return true;
        }
        return false;

    }
};