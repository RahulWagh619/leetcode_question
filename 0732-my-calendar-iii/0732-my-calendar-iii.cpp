class MyCalendarThree {
public:
    vector<pair<int,int>>vp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        //  vp=rvp;
        vp.push_back({startTime,1});
        vp.push_back({endTime,-1});
        sort(vp.begin(),vp.end());
        int cur=0;
        int val=-1;
        // bool val=true;
        for(int i=0;i<vp.size();i++){
            cur+=vp[i].second;
            if(cur>val){
                val=cur;
            }
        }
        // if(val){
            //  rvp.push_back({startTime,1});
            //  rvp.push_back({endTime,-1});
        // }
        return val;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */