// Last updated: 8/13/2025, 3:37:15 PM
class Solution
{
public:
    int dp[502][502];
    // int helper(string &word1, string &word2, int i1, int i2)
    // {
    //     if (i1 == word1.length())
    //         return word2.length() - i2;
    //     if (i2 == word2.length())
    //         return word1.length() - i1;
    //     if (dp[i1][i2] != -1)
    //         return dp[i1][i2];
    // }
    int minDistance(string word1, string word2)
    {
        // memset(dp, 0, sizeof dp);
        int n = word1.length();
        int m = word2.length();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        // return helper(word1,word2,0,0);
        for (int j = 0; j <=m; j++)
        {
            prev[j] = m - j;
        }
        // for (int i = 0; i <= n; i++)
        // {
        //    prev[m] = n - i;
        // }
        for (int i = n - 1; i >= 0; i--)
        {
            curr[m]=n-i;
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                     curr[j] = prev[j + 1];
                }
                else{
                 curr[j] = min({1 + prev[j], 1 + curr[j + 1], 1 + prev[j + 1]});
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};