class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>>ans;
        int n=segments.size();
        vector<pair<long long,long long>>vp;
        vector<pair<long long,long long>>vp1;
        for(int i=0;i<n;i++){
            vp.push_back({segments[i][0],segments[i][2]});
            vp.push_back({segments[i][1],-segments[i][2]});
        }
        sort(vp.begin(),vp.end());
       int i = 0;

while(i < vp.size()) {

    long long pos = vp[i].first;
    long long sum = 0;

    while(i < vp.size() && vp[i].first == pos) {

        sum += vp[i].second;
        i++;
    }

    vp1.push_back({pos, sum});
}
        long long val=0;
        for(int i=0;i<vp1.size()-1;i++){
               val+=vp1[i].second;
               if(val>0){
                 ans.push_back({
                    vp1[i].first,
                    vp1[i+1].first,
                    val
                });
               }
        }
        return ans;
    }
};