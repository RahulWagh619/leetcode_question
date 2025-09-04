class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>vp;
        for(int i=0;i<points.size();i++){
           vp.push_back({points[i][0],points[i][1]});
        }
        sort(vp.begin(),vp.end());
        int start=vp[0].first;
        int end=vp[0].second;
        int count=1;
        for(int i=1;i<vp.size();i++){
             if(max(start,vp[i].first)>min(end,vp[i].first)){
                count++;
                start=vp[i].first;
                end=vp[i].second;
             }
             else{
                start=max(start,vp[i].first);
                end=min(end,vp[i].second);
             }
        }
        return count;
    }
};