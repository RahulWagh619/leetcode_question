class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>vp;
        for(int i=0;i<trips.size();i++){
            vp.push_back({trips[i][1],trips[i][0]});
            vp.push_back({trips[i][2],-trips[i][0]});
        }
        sort(vp.begin(),vp.end());
        int count=0;
        for(int i=0;i<vp.size();i++){
            //  if(vp[i].second<0){
            //     count-=vp[i].second;
            //  }
            //  else{
                count+=vp[i].second;
            //  }
             if(count>capacity){
                return false;
                break;
             }
        }
        return true;
    }
};