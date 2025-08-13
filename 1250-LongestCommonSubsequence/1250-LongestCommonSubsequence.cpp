// Last updated: 8/13/2025, 3:34:20 PM
class Solution {
public:

// int dp[1002][1002];
// int helper(string text1, string text2,int i1,int i2){
//     if(i1==text1.size()||i2==text2.size())return 0;
//     if(dp[i1][i2]!=-1)return dp[i1][i2];
    
// }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp,0,sizeof dp);
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=0;i<=m;i++){
           prev[i]=0;
        }
        for(int i=0;i<=n;i++){
            prev[m]=0;
        }

        for(int i1=n-1;i1>=0;i1--){
            for(int i2=m-1;i2>=0;i2--){
                 if(text1[i1]==text2[i2]){
         curr[i2]=1+prev[i2+1];
    }
    else{
   curr[i2]= max(prev[i2],curr[i2+1]);
    }
            }
            prev=curr;
        }
        return prev[0];
    }
};