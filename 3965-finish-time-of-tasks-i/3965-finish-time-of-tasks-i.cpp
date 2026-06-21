class Solution {
public:
long long helper(int node,vector<vector<int>>&adj,vector<long long>&val,vector<int>& baseTime){
       if(adj[node].size()==0){
         return val[node];
       }
       int size=adj[node].size();
       long long mini=LLONG_MAX;
       long long maxi=LLONG_MIN;
       for(int i=0;i<size;i++){
          long long v=helper(adj[node][i],adj,val,baseTime);
          mini=min(mini,v);
          maxi=max(maxi,v);
       }
       long long z=maxi-mini+baseTime[node];
       return val[node]=maxi+z;
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
          vector<vector<int>>adj(n);
          vector<long long>val(n);
          for(int i=0;i<n;i++){
             val[i]=baseTime[i];
          }
          for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
          }
          return helper(0,adj,val,baseTime);
    }
};