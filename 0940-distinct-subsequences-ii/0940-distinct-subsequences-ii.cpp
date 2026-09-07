class Solution {
public:
int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.length();
        map<char,int>mpp;
        mpp[s[0]]=0;
        vector<int>dp(n,1);
        // dp[0]=1;
        for(int i=1;i<n;i++){
            // dp[i]=1;
            if(mpp.find(s[i])!=mpp.end()){
                int idx=mpp[s[i]]-1;
                dp[i]=(dp[i]+dp[i-1])%mod;
                dp[i]=(dp[i]+dp[i-1])%mod;
                if(idx==-1){
                    dp[i]=(dp[i]-1);
                }
                else{
                dp[i]=(dp[i]-dp[idx]-1+mod)%mod;
                }
            }
            else{
                dp[i]=(dp[i]+dp[i-1])%mod;
                dp[i]=(dp[i]+dp[i-1])%mod; 
            }
            mpp[s[i]]=i;
        }
        return dp[n-1];
    }
};