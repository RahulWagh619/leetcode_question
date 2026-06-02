class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            int time=landStartTime[i]+landDuration[i];
                 if(landStartTime[i]>waterStartTime[j]){
                    continue;
                   }
                if(waterStartTime[j]<=time){
                   time+=waterDuration[j];
                }
                else{
                  time=waterDuration[j]+waterStartTime[j];
                }
                mini=min(mini,time);
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
            int time=waterDuration[j]+waterStartTime[j];
               if(landStartTime[i]<waterStartTime[j]){
                    continue;
                   }
                if(landStartTime[i]<=time){
                   time+=landDuration[i];
                }
                else{
                  time=landDuration[i]+landStartTime[i];
                }
                mini=min(mini,time);
            }
        }
        return mini;
    }
};