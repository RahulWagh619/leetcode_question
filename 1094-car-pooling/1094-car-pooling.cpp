class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<trips.size();i++){
            int from=trips[i][1];
            int to=trips[i][2];
            int total=trips[i][0];
            vp.push_back({from,total});
            vp.push_back({to,-total});
        }
        sort(vp.begin(),vp.end());
        int cur=0;
        for(int i=0;i<vp.size();i++){
            cur+=vp[i].second;
            if(cur>capacity){
                return false;
            }
        }
        return true;
    }
};