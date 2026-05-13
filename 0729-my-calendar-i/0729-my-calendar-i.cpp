class MyCalendar {
public:
    map<int,int>mpp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int start=startTime;
        int end=endTime;
        auto it=mpp.lower_bound(start);
        if(it!=mpp.end() && it->first<end){
            return false;
        }
        if(it != mpp.begin()) {
            auto prevIt = prev(it);

            if(prevIt->second > start)
                return false;
        }
        mpp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */