class Solution {
public:
int dp[102][5002];
long long helper(int i,vector<vector<pair<int, int>>>&a,int sum){
    int n=a.size();
    if(sum==0)return 0;
    if(i>=n)return INT_MAX;
    if(dp[i][sum]!=-1)return dp[i][sum];
    long long pick=INT_MAX;
    for(int j=0;j<a[i].size();j++){
        if(a[i][j].first<=sum){
             pick=min(pick,helper(i+1,a,sum-a[i][j].first)+a[i][j].second);
        }
        else{
            break;
        }
    }
    long long notpick=helper(i+1,a,sum);
    return dp[i][sum]=min(pick,notpick);
}
    int minOperations(vector<int>& nums, int sum) {
        memset(dp,-1,sizeof dp);
        int n = nums.size();
        vector<vector<pair<int, int>>> a(n);
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int count = 0;
            if (val <= sum) {
                a[i].push_back({val, count});
            }
            while (val >0) {
                val /= 2;
                count++;
                if (val <= sum) {
                    a[i].push_back({val, count});
                }
            }
            // a[i].push_back({val, count});
            val = nums[i] * 2;
            count = 1;
            while (val <= sum) {
                a[i].push_back({val, count});
                val*=2;
                count++;
            }
            sort(a[i].begin(),a[i].end());
        }
        int val=helper(0,a,sum);
        if(val==INT_MAX)return -1;
        return val;
    }
};