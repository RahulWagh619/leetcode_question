// Last updated: 8/13/2025, 3:36:21 PM
class MinStack {
public:
vector<pair<int,int>>a;
    MinStack() {
        
    }
    
    void push(int val)  {
        if(a.empty()){
            pair<int,int>p;
            p.first=val;
            p.second=val;
            a.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            p.second=min(val,a.back().second);
            a.push_back(p);
        }
    }
    
    void pop() {
        if(!a.empty()){
         a.pop_back();
        }
    }
    
    int top() {
        return a.back().first;
    }
    
    int getMin() {
        return a.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */