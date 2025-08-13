// Last updated: 8/13/2025, 3:37:05 PM
class Solution
{
public:
    int dp[102];
    // int helper(string &s, int i)
    // {
    //     if (i == s.length())
    //     {
    //         return 1;
    //     }
    //     if (dp[i] != -1)
    //         return dp[i];
    // }
    int numDecodings(string s)
    {
        // if(s[0]=='0'){
        //     return 0;
        // }
        // bool ans=true;
        // for(int i=1;i<s.length();i++){
        //     if(s[i]=='0'){
        //         if(s[i-1]>='3'||s[i-1]=='0'){
        //             ans=false;
        //             break;
        //         }
        //     }
        // }
        // if(!ans){
        //     return 0;
        // }
        memset(dp, 0, sizeof dp);
        int n = s.length();
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                int pick = dp[i + 1];
                if (i + 1 < s.length())
                {
                    int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (val >= 10 && val <= 26)
                    {
                        pick += dp[i + 2];
                    }
                }
                dp[i] = pick;
            }
        }
        return dp[0];
    }
};