class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]}); // {destination, price}
        }
        
        // dist[node][stops] = minimum cost to reach 'node' using 'stops'
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        
        // priority_queue of {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = top[0];
            int node = top[1];
            int stops = top[2];
            
            // If we reach destination, return cost
            if (node == dst) return cost;
            
            // If stops exceeded, skip
            if (stops > k) continue;
            
            // Explore neighbors
            for (auto &edge : adj[node]) {
                int next = edge.first;
                int price = edge.second;
                int newCost = cost + price;
                
                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }
        
        return -1;
    }
};
