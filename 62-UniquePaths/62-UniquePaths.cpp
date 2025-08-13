// Last updated: 8/13/2025, 3:37:24 PM
class Solution {
public:
    int dp[102][102];

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);  // Optional if we manually assign all dp[i][j]

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
