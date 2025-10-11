class Solution {
public:
typedef long long ll;
// ll dp[100002];
// ll helper(int i,vector<int>& power, unordered_map<ll,ll>&mpp){
//     if(i>=power.size()){
//         return 0;
//     }
//     if(dp[i]!=-1)return dp[i];
//     ll maxi=INT_MIN;
//     ll val=upper_bound(power.begin(),power.end(),power[i]+2)-power.begin();
//     ll pick=helper(val,power,mpp)+power[i]*mpp[power[i]];
//     ll notpick=helper(i+1,power,mpp);
//     return dp[i]=max(pick,notpick);
// }
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        vector<ll>dp(n+1,0);
        sort(power.begin(),power.end());
        unordered_map<ll,ll>mpp;
        for(int i=0;i<n;i++){
            mpp[power[i]]++;
        }
        for(int i=n-1;i>=0;i--){
        ll val=upper_bound(power.begin(),power.end(),power[i]+2)-power.begin();
          ll pick=dp[val]+power[i]*mpp[power[i]];
          ll next=upper_bound(power.begin(),power.end(),power[i])-power.begin();
          ll notpick=dp[next];
          dp[i]=max(pick,notpick);
        }
        return dp[0];
    }
};