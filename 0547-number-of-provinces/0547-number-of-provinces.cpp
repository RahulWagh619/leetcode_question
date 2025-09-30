class Solution {
public:
void bfs(int val, vector<int>&vis,vector<vector<int>>& isConnected){
      queue<int>q;
      q.push(val);
      vis[val]=1;
      while(!q.empty()){
          int z=q.front();
          q.pop();
           for(int i=0;i<isConnected.size();i++){
            if(isConnected[z][i]==1 && vis[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
      }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<int>vis(isConnected.size(),0);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                bfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};