class Solution {
public:
typedef long long ll;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<ll>>mat(n,vector<ll>(n,LLONG_MAX));
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int val=edges[i][2];
            mat[u][v]=val;
            mat[v][u]=val;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==LLONG_MAX||mat[k][j]==LLONG_MAX){
                        continue;
                    }
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        ll mini=INT_MAX;
        vector<pair<ll,ll>>vp;
        for(int i=0;i<n;i++){
            ll count=0;
            for(int j=0;j<n;j++){
                 if(i!=j){
                    if(mat[i][j]<=distanceThreshold){
                        count++;
                    }
                 }
            }
            if(mini>=count){
                 mini=count;
                 vp.push_back({mini,i});
            }
        }
        sort(vp.begin(),vp.end());
        int idx=-1;
        for(int i=0;i<vp.size();i++){
            if(vp[i].first!=mini){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return vp[vp.size()-1].second;
        }
        return vp[idx-1].second;
    }
};