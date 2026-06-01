class Solution {
public:
int dp[1002][1502];
int helper(vector<vector<int>>& items, int budget,int i,vector<int>&count,int &mini){
     int n=items.size();
     if(i>=n)return budget/mini;
     if(dp[i][budget]!=-1)return dp[i][budget];
     int pick=0;
     if(items[i][1]<=budget){
        pick=count[i]+helper(items,budget-items[i][1],i+1,count,mini);
     }
     int notpick=helper(items,budget,i+1,count,mini);
     return dp[i][budget]=max(pick,notpick);
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n=items.size();
        memset(dp,-1,sizeof(dp));
     vector<int>count(n);
     int mini=INT_MAX;
    map<int,int>mpp;
     int maxi=INT_MIN;
     for(int i=0;i<n;i++){
        mpp[items[i][0]]++;
        maxi=max(maxi,items[i][0]);
        mini=min(mini,items[i][1]);
     }
     for(int i=0;i<n;i++){
         long long val=0;
         for(int j=items[i][0];j<=maxi;j+=items[i][0]){
            val+=mpp[j];
         }
        //  val--;
         count[i]=val;
     }
         return helper(items,budget,0,count,mini);
    }
};