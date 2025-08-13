// Last updated: 8/13/2025, 3:33:37 PM
class Solution
{
public:
    // int dp[302][302];
    const int mod = 1e9 + 7;
    long long power(int a, int b, int mod) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % mod;
            a = (1LL * a * a) % mod;
            b /= 2;
        }
        return res;
    }
    int numberOfWays(int n, int x)
    {
        // memset(dp, 0, sizeof dp);
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);

         for (int i = 1; i <= n+1; i++) {
            prev[0] = 1;
         }
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                int notpick = prev[j];
                int pick = 0;
                if (j - power(i, x, mod) >= 0)
                {
                    pick = prev[j-power(i,x,mod)];
                }
                curr[j] = ((pick) % mod + (notpick) % mod) % mod;
            }
            prev=curr;
        }
        return prev[n];
    }
};