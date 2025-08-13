// Last updated: 8/13/2025, 3:35:06 PM
class Solution {
public:
    int dp[502][502];

    int helper(string &word1, string &word2, int i1, int i2) {
        if (i1 == word1.length() || i2 == word2.length()) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];

        if (word1[i1] == word2[i2]) {
            return dp[i1][i2] = 1 + helper(word1, word2, i1 + 1, i2 + 1);
        }

        return dp[i1][i2] = max(helper(word1, word2, i1 + 1, i2),
                                helper(word1, word2, i1, i2 + 1));
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        int lcsLen = helper(word1, word2, 0, 0);
        return word1.length() + word2.length() - 2 * lcsLen;
    }
};
