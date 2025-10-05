class Solution {
public:
bool dfs(int node,int pcolor,vector<int>&color,vector<vector<int>>& graph){
      if(color[node]==-1){
           if(pcolor==1){
            color[node]=0;
           }
           else{
            color[node]=1;
           }
           for(int i=0;i<graph[node].size();i++){
               if(color[graph[node][i]]==-1){
                   if(!dfs(graph[node][i],color[node],color,graph)){
                    return false;
                   }

               }
               else{
                   if(color[graph[node][i]]==color[node]){
                    return false;
                   }
               }
           }
      }
      if(color[node]==pcolor){
      return false;
      }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
               if(!dfs(i,1,color,graph)){
                return false;
               }
            }
        }
        return true;
    }
};