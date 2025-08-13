// Last updated: 8/13/2025, 3:36:49 PM
class Solution
{
public:
const int MOD = 1e9 + 7;
    // long long dp[1002][1002];

    int numDistinct(string s, string t)
    {
        // memset(dp, 0, sizeof dp);
        int n = s.length();
        int m = t.length();
        vector<long long>prev(m+1,0);
        vector<long long>curr(m+1,0);

        // Base case: If t is empty, 1 way to match it
        // for (int i = 0; i <= n; i++) {
            prev[m] = 1;
        // }

        for (int i = n - 1; i >= 0; i--)
        {
            curr[m] = 1;
            for (int j = m - 1; j >= 0; j--)
            {
                long long pick = 0;
                if (s[i] == t[j])
                {
                    pick = prev[j + 1];
                }
                long long notpick = prev[j];
                curr[j] = (pick + notpick)%MOD;
            }
            prev=curr;
        }

        return prev[0];
    }
};
