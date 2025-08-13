// Last updated: 8/13/2025, 3:34:31 PM
class Solution {
public:
int dp[502];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,0,sizeof dp);
        // return helper(arr,0,k);
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int maxi=-1e9;
    int currmax=-1;
    for(int j=i;j < min(n, i + k);j++){
        currmax=max(currmax,arr[j]);
        int cost=(currmax*(j-i+1))+dp[j+1];
        maxi=max(maxi,cost); 
    }
     dp[i]=maxi;

        }
        return dp[0];
    }
};