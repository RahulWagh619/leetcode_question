class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        int q=queries.size();
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];
            for(int j=l;j<=r;j+=k){
              nums[j]=(1LL*(nums[j] % mod)*(v % mod))%mod;
            }
        }
        int val=0;
        for(int i=0;i<nums.size();i++){
            val=(val ^ nums[i]);
        }
        return val;
    }
};