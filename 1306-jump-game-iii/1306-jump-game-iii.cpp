class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            int left=idx-arr[idx];
            int right=idx+arr[idx];
            if(left>=0 && left<n){
                if(vis[left]==0){
                    vis[left]=1;
                    q.push(left);
                }
            }
            if(right>=0 && right<n){
                if(vis[right]==0){
                    vis[right]=1;
                    q.push(right);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && vis[i]==1)return true;
        }
        return false;
    }
};