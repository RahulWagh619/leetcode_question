class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj;
        int n=prerequisites.size();
        adj.resize(numCourses);
        vector<int>vis(numCourses,0);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                vis[i]=1;
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(int i=0;i<adj[val].size();i++){
                int z=adj[val][i];
                if(vis[z]==0){
                    indegree[z]--;
                    if(indegree[z]==0){
                        vis[z]=1;
                        q.push(z);
                    }
                }
            }
            ans.push_back(val);
        }
            if(ans.size()!=numCourses){
                return {};
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};