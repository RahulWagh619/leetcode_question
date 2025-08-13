// Last updated: 8/13/2025, 3:34:53 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float>st;
        if(speed.size()==1){
            return 1;
        }
        else{
            // int count=0;
            vector<pair<int,int>>p;
            for(int  i=0;i<speed.size();i++){
                p.push_back({position[i],speed[i]});
            }
            sort(p.begin(),p.end());
            vector<float>time;
            for(int i=0;i<p.size();i++){
                int change=target-p[i].first;
                float diff=(float)change/p[i].second;
                time.push_back(diff);
            }
            for(int i=time.size()-1;i>=0;i--){
                if(i==time.size()-1||time[i]>st.top()){
                    st.push(time[i]);
                }
            }
            if(st.empty()){
                return 1;
            }
            else{
                return st.size();
            }
        }
        
    }
};