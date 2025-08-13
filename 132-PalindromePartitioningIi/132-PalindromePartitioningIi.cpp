// Last updated: 8/13/2025, 3:36:34 PM
class Solution
{
public:
    int dp[2002];
    bool ispalindrome(string &k)
    {
        int i = 0;
        int j = k.length() - 1;
        while (i < j)
        {
            if (k[i] != k[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
}
    int minCut(string s)
    {
        memset(dp, 0, sizeof dp);
        //  return helper(s,0);
        int n = s.length();
        dp[n]=0;
        for (int i = n-1; i >= 0; i--)
        {
        int mini = INT_MAX;
        string temp = "";
            for (int j = i; j < n; j++)
            {
                // if(i>j)continue;
                temp += s[j];
                if (ispalindrome(temp))
                {
                    int cost = 1+dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};