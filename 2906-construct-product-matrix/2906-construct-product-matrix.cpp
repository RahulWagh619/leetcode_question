class Solution {
public:
int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>pf(n,vector<int>(m));
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>sf(n,vector<int>(m));
        sf[n-1][m-1]=1;
        pf[n-1][m-1]=1;
        int val=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pf[i][j]=val;
                val=((val%mod)*(grid[i][j]%mod))%mod;
            }
        }
        val=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                sf[i][j]=val;
                val=((val%mod)*(grid[i][j]%mod))%mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int z=((pf[i][j]%mod)*(sf[i][j]%mod))%mod;
                ans[i][j]=z;
            }
        }
        return ans;
    }
};