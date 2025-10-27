class Solution {
public:
typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        const ll mod = 1e9 + 7;
        vector<vector<pair<ll,ll>>> edges(n);
        
        for(ll i = 0; i < roads.size(); i++){
            ll u = roads[i][0];
            ll v = roads[i][1];
            ll val = roads[i][2];
            edges[u].push_back({v, val});
            edges[v].push_back({u, val});
        }
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0, 0});
        
        vector<ll> dis(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        ways[0] = 1;
        dis[0] = 0;
        
        while(!pq.empty()){
            auto [val, node] = pq.top();
            pq.pop();
            
            // Skip if we've already processed this node with a better distance
            if(val > dis[node]) continue;
            
            for(ll i = 0; i < edges[node].size(); i++){
                ll cnode = edges[node][i].first;
                ll cval = edges[node][i].second;
                
                if(dis[cnode] > cval + dis[node]){
                    dis[cnode] = cval + dis[node];
                    ways[cnode] = ways[node];
                    pq.push({dis[cnode], cnode});
                }
                else if(dis[cnode] == cval + dis[node]){
                    ways[cnode] = (ways[cnode] + ways[node]) % mod;
                }
            }
        }
        
        if(dis[n-1] == LLONG_MAX){
            return 0;
        }
        return ways[n-1];
    }
};
