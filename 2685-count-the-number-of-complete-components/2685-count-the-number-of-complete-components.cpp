class Solution {
public:
class DisjointSet{
     vector<int>parent,size;
     public:
     DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
     }
     int finduparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=finduparent(parent[node]);
     }
     void usize(int u,int v){
        int up=finduparent(u);
        int vp=finduparent(v);
        if(up==vp)return;
        if(size[up]>size[vp]){
            parent[vp]=up;
            size[up]+=size[vp];
        }
        else{
            parent[up]=vp;
            size[vp]+=size[up];
        }
     }
};
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<set<int>>adj(n);
        map<int,vector<int>>mpp;
        for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].insert(v);
           adj[v].insert(u);
           ds.usize(u,v);
        }
        for(int i=0;i<n;i++){
            mpp[ds.finduparent(i)].push_back(i);
        }
        int count=0;
        for(auto &i:mpp){
            vector<int>a=i.second;
            if(a.size()<=2){
                count++;
                continue;
            }
            bool ans=true;
            for(int j=0;j<a.size();j++){
                for(int k=j+1;k<a.size();k++){
                    if(adj[a[k]].find(a[j])==adj[a[k]].end()){
                        ans=false;
                        break;
                    }
                }
            }
            if(ans){
                count++;
            }
        }
        return count;
    }
};