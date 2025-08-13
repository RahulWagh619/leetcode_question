// Last updated: 8/13/2025, 3:33:44 PM
class Solution {
public:
const int MOD=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>val;
        vector<int>ans;
        // int k=n;
        int size=log2(n);
        for(int i=0;i<=size;i++){
            if((n>>i)& 1){
                val.push_back(1<<i);
            }
        }
        for(int i=0;i<queries.size();i++){
            long long k=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                k=((k%MOD)*(val[j]%MOD))%MOD;
            }
                ans.push_back(k);
        }
        return ans;
    }
};