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
    int makeConnected(int n, vector<vector<int>>& connections) {
        set<int>st;
        DisjointSet ds(n);
        int count=0;
        // sort(connections.begin(),connections.end());
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            st.insert(u);
            st.insert(v);
            if(ds.finduparent(u)==ds.finduparent(v)){
                count++;
            }
            else{
                ds.usize(u,v);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.finduparent(i)==i){
                comp++;
            }
        }
        int nd=comp-1;
        if(nd>count){
            return -1;
        }
        return nd;
    }
};