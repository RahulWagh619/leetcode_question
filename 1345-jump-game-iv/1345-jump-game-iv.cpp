class Solution {
public:
    int minJumps(vector<int>& a) {
        int n=a.size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[a[i]].push_back(i);
        }
        vector<int>dis(n,INT_MAX);
        vector<int>vis(n,0);
        dis[0]=0;
        queue<int>q;
        q.push(0);
            vis[0]=1;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            // if(mpp[a[val]].empty()){
            //     mpp[a[val]].clear();
            // }
            // else{
                for(auto &i:mpp[a[val]]){
                    if(!vis[i]){
                    q.push(i);
                    dis[i]=dis[val]+1;
                    vis[i]=1;
                    }
                }
                mpp[a[val]].clear();
            // }
            if(val>0){
               if(!vis[val-1]){
                   q.push(val-1);
                   vis[val-1]=1;
                  dis[val-1]=dis[val]+1;
               }
            }
            if(val<n-1){
                 if(!vis[val+1]){
                   q.push(val+1);
                   vis[val+1]=1;
                  dis[val+1]=dis[val]+1;
                }
            }
        }
        int ans=dis[n-1];
        return ans;
    }
};