class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int size=roads.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<size;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // dis[1]=0;
        pq.push({1,INT_MAX});
        while(!pq.empty()){
            int node=pq.top().first;
            int wt=pq.top().second;
            pq.pop();
            if(wt>dis[node])continue;
            for(int i=0;i<adj[node].size();i++){
                int m1=adj[node][i].first;
                int m2=adj[node][i].second;
                int mini=min({dis[node],dis[m1],m2});
                if(dis[m1]>mini){
                    dis[m1]=mini;
                    pq.push({m1,dis[m1]});
                }
            }
        }
        return dis[n];
    }
};