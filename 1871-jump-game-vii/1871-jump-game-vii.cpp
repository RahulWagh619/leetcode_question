class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1')return false;
        vector<int>vis(n,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        int far=0;
        while(!q.empty()){
             int idx=q.front();
             q.pop();
             int start=max(far,idx+minJump);
             int end=min(n-1,idx+maxJump);
             for(int i=start;i<=end;i++){
                if(s[i]=='0' && !vis[i]){
                    if(i==n-1){
                        return true;
                    }
                    q.push(i);
                    vis[i]=1;
                }
             }
             far=max(far,end+1);
        }
        return false;
    }
};