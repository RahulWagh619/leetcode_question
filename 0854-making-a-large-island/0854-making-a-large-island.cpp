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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n;
        // int count=0;
        DisjointSet ds(n*n);
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if(x>=0 && x<n && y>=0 && y<n){
                            if(grid[x][y]==1){
                                ds.usize((x*n)+y,(i*n)+j);
                            }
                        }
                    }
                }
            }
        }
        map<int,int>mpp;
        for(int i=0;i<n*m;i++){
            int val=ds.finduparent(i);
            mpp[val]++;
        }
        vector<int>z(n*m);
        int count=INT_MIN;
        for(int i=0;i<n*m;i++){
             z[i]=mpp[i];
             count=max(count,z[i]);
        }
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                int size = 1;  
                set<int> neighbors; 
                for(int k = 0; k < 4; k++){
                    int x = i + dr[k];
                    int y = j + dc[k];
                    if(x >= 0 && x < n && y >= 0 && y < n){
                        if(grid[x][y] == 1){
                            int parent = ds.finduparent((x*n) + y);
                            neighbors.insert(parent);
                        }
                    }
                }
                
                for(int parent : neighbors){
                    size += z[parent];
                }
                
                 count = max(count, size);
            }
        }
    }
        return count;
    }
};