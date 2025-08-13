// Last updated: 8/13/2025, 3:37:37 PM
class Solution
{
public:
    // int dp[2002][2002];
    // bool helper(string s, string p, int i1, int i2)
    // {
    //     if (i1 == s.length() && i2 == p.length())
    //     {
    //         return true;
    //     }
    //     if (i2 >= p.length())
    //         return false;
    //     if (i1 == s.length())
    //     {
    //         for (int i = i2; i < p.length(); ++i)
    //             if (p[i] != '*')
    //                 return false;
    //         return true;
    //     }
    //     if (dp[i1][i2] != -1)
    //         return dp[i1][i2];
    //     // bool pick=false;
        
    // }
    bool isMatch(string s, string p)
    {
        // memset(dp, 0, sizeof dp);
        int n = s.length();
        int m = p.length();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
       prev[m] = 1;
        for (int j = m - 1; j >= 0; --j)
        {
            if (p[j] == '*')
                prev[j] = prev[j + 1];
            else
                break;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                bool pick=false;
                if (p[j] == '*')
        {
           pick=prev[j] ||curr[j + 1];
        }
        else if (p[j] == '?' || p[j] == s[i])
        {
            pick = prev[j + 1];
        }
         curr[j] = pick;
            }
            prev=curr;
        }
        return prev[0];
        // return helper(s,p,0,0);
    }
};