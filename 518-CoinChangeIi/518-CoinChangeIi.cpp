// Last updated: 8/13/2025, 3:35:18 PM
class Solution {
public:
    const long long MOD = 1e11;
    // int dp[303][5002];

    int change(int amount, vector<int> &coins) {
        int n = coins.size();

        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        for (int val = 1; val <= amount; val++)
            prev[val] = 0;
        // for (int i = 0; i <= n; i++)
           prev[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int val = 0; val <= amount; val++) {
                int pick = 0;
                if (coins[i] <= val)
                    pick = curr[val - coins[i]];
                int notpick = prev[val];
                curr[val] = ((pick%MOD) + (notpick%MOD))%MOD;
            }
            prev=curr;
        }

        return prev[amount];
    }
};
