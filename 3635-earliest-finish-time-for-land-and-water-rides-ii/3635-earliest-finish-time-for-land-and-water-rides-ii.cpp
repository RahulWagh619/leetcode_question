class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<pair<int,int>>l;
        vector<pair<int,int>>w;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        vector<int>mini1(n);
        vector<int>mini2(m);

        vector<int>sf1(n);
        vector<int>sf2(m);
        for(int i=0;i<n;i++){
            l.push_back({landStartTime[i],landDuration[i]});
        }
        for(int i=0;i<m;i++){
            w.push_back({waterStartTime[i],waterDuration[i]});
        }
        sort(l.begin(),l.end());
        sort(w.begin(),w.end());
        // sort(add1.begin(),add1.end());
        // sort(add2.begin(),add2.end());
        mini1[0]=l[0].second;
        mini2[0]=w[0].second;
        sf1[n-1]=l[n-1].second+l[n-1].first;
        sf2[m-1]=w[m-1].second+w[m-1].first;
        for(int i=1;i<n;i++){
            mini1[i]=min(mini1[i-1],l[i].second);
        }
        for(int i=1;i<m;i++){
            mini2[i]=min(mini2[i-1],w[i].second);
        }
        for(int i=n-2;i>=0;i--){
            sf1[i]=min(sf1[i+1],l[i].second+l[i].first);
        }
        for(int i=m-2;i>=0;i--){
            sf2[i]=min(sf2[i+1],w[i].second+w[i].first);
        }
        int time=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            time=l[i].first+l[i].second;
            auto it = upper_bound(w.begin(), w.end(), make_pair(time, INT_MAX));
               int idx = it - w.begin();
            if(it==w.begin()){
                time=sf2[idx];
            }
            else if(it==w.end()){
                time+=mini2[m-1];
            }
            else{
               int time1=sf2[idx];
               time+=mini2[idx-1];
               time=min(time1,time);
            }
            ans=min(time,ans);
        }
        for(int i=0;i<m;i++){
            time=w[i].first+w[i].second;
            auto it = upper_bound(l.begin(), l.end(), make_pair(time, INT_MAX));
            // auto it2 = upper_bound(add1.begin(), add1.end(),time);
               int idx = it - l.begin();
            if(it==l.begin()){
                time=sf1[idx];
            }
            else if(it==l.end()){
                time+=mini1[n-1];
            }
            else{
               int time1=sf1[idx];
               time+=mini1[idx-1];
               time=min(time1,time);
            }
            ans=min(time,ans);
        }
        return ans;
    }
};