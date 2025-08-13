// Last updated: 8/13/2025, 3:34:13 PM
class Solution {
public:
int dp[1002][1002];

// int helper(string &s,string &k,int i1,int i2){
//     if(i1==s.length()||i2==k.length())return 0;
//     if(dp[i1][i2]!=-1)return dp[i1][i2];
//     if(s[i1]==k[i2]){
//         return dp[i1][i2]= 1+helper(s,k,i1+1,i2+1);
//     }
//     return dp[i1][i2]=max(helper(s,k,i1+1,i2),helper(s,k,i1,i2+1));
// }
    int minInsertions(string s) {
        string k = s;
        reverse(s.begin(), s.end());
        // memset(dp, 0, sizeof dp);
        int n = s.length();
        int m = k.length();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        // for (int i = 0; i <= n; i++)
        // {
            prev[m] = 0;
        // }
        for (int i = 0; i <= m; i++)
        {
            prev[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m-1; j>=0; j--)
            {
                if (s[i] == k[j])
                {
                   curr[j] = 1 + prev[j + 1];
                }
                else{
                curr[j] = max(prev[j],curr[ j + 1]);
                }
            }
            prev=curr;
        }
        return s.length()-prev[0];
    }
};