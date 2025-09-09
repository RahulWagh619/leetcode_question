class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1,0);
        dp[1]=1;
        long long share=0;
        long long MOD = 1e9 + 7;
        for(int i=2;i<=n;i++){
            if(i>delay){
                share=(share+dp[i-delay])%MOD;
            }
            if(i>forget){
                share=(share-dp[i-forget]+MOD)%MOD;
            }
            dp[i]=share;
        }
        long long total_aware = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            total_aware = (total_aware + dp[i]) % MOD;
        }
        
        return total_aware;
    }
};