class MyCalendar {
public:
   vector<pair<int,int>>vp;
   vector<pair<int,int>>rvp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        vp=rvp;
        vp.push_back({startTime,1});
        vp.push_back({endTime,-1});
        sort(vp.begin(),vp.end());
        int cur=0;
        bool val=true;
        for(int i=0;i<vp.size();i++){
            cur+=vp[i].second;
            if(cur>1){
                val=false;
                break;
            }
        }
        if(val){
             rvp.push_back({startTime,1});
             rvp.push_back({endTime,-1});
        }
        return val;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */