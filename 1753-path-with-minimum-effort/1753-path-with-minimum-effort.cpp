class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<int>dis(n*m,INT_MAX);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        map<pair<int,int>,int>mpp;
        int val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[{i,j}]=val;
                val++;
            }
        }
        dis[0]=0;
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        while(!pq.empty()){
            int val=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1 && y==m-1){
                break;
                 
            }
            pq.pop();
            for(int k=0;k<4;k++){
                int i=x+dr[k];
                int j=y+dc[k];
                if(i>=0 && i<n && j>=0 && j<m){
                    if(dis[mpp[{i,j}]]>max(val,abs(heights[i][j]-heights[x][y]))){
                        int z=abs(heights[i][j]-heights[x][y]);
                        pq.push({max(z,val),{i,j}});
                        dis[mpp[{i,j}]]=max(val,z);
                    }
                }

            }
            
        }
         return dis[mpp[{n-1,m-1}]];
    }
};