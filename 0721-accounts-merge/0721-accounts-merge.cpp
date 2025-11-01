class Solution {
public:
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int finduparent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = finduparent(parent[node]);
    }

    void urank(int u, int v)
    {
        int up = finduparent(u);
        int vp = finduparent(v);
        if (up == vp)
            return;
        if (rank[up] > rank[vp])
        {
            parent[vp] = up;
        }
        else
        {
            parent[up] = vp;
            rank[vp]++;
        }
    }

    void usize(int u, int v)
    {
        int up = finduparent(u);
        int vp = finduparent(v);
        if (up == vp)
            return;
        if (size[up] > size[vp])
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
        else
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        int n=accounts.size();
        map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                   if(mpp.find(accounts[i][j])==mpp.end()){
                     mpp[accounts[i][j]]=i;
                   }
                   else{
                       ds.usize(i,mpp[accounts[i][j]]);
                   }
            }
        }
        map<int, set<string>> mpp2;
    for (int i = 0; i < n; i++) {
        int parent = ds.finduparent(i);
        for (int j = 1; j < accounts[i].size(); j++) { 
            mpp2[parent].insert(accounts[i][j]);
        }
    }
        vector<vector<string>>v;
        for(auto &i:mpp2){
            set<string> z=i.second;
            int node=i.first;
            vector<string>m;
            m.push_back(accounts[node][0]);
            for(auto &j:z){
                m.push_back(j);
            }
            v.push_back(m);
        }
        return v;
    }
};