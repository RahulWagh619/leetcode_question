// Last updated: 8/13/2025, 3:34:07 PM
class Solution
{
public:
    int dp[105][105];
    // int helper(vector<int>&val,int i,int j){
    //     if(j<i)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     long long mini=INT_MAX;
    //     for(int index=i;index<=j;index++){
    //          long long cost=val[j+1]-val[i-1]+helper(val,i,index-1)+helper(val,index+1,j);
    //          mini=min(cost,mini);
    //     }
    //     return dp[i][j]=mini;
    // }
    int minCost(int n, vector<int> &cuts)
    {
        vector<int> val = cuts;
        val.push_back(0);
        val.push_back(n);
        sort(val.begin(), val.end());
        memset(dp, 0, sizeof dp);
        int size = val.size();
        // return helper(val,1,val.size()-2);
        for (int i = size-2; i>=1; i--)
        {
            for (int j = 1; j <=size-2; j++)
            { 
                if(i>j)continue;
                /* code */
                int mini = INT_MAX;
                for (int index = i; index <= j; index++)
                {
                    int cost = val[j + 1] - val[i - 1] + dp[i][index - 1] + dp[index + 1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
            
        }
        return dp[1][size - 2];
    }
};