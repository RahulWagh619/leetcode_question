class Solution {
public:
// const int N = 1000000;
const long long MOD = 1000000007LL;
 vector<long long> fact;
    vector<long long> invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void build(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

long long nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
         vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        q.push({1, 0});

        vector<int> vis(n + 1, 0);
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nxt : adj[node]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push({nxt, depth + 1});
                }
            }
        }
        build(maxDepth);
        long long ways=0;
        for(int i=1;i<=maxDepth;i+=2){
            // int z=max(i,depth-i);
            ways = (ways + nCr(maxDepth, i)) % MOD;
        }
        return ways;

    }
};