class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(i);
        }
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()){
                continue;
            }
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(st.find(j)!=st.end()){
                        int c=intervals[j][0];
                        int d=intervals[j][1];
                        int a=intervals[i][0];
                        int b=intervals[i][1];
                        if(c<=a && b<=d){
                            st.erase(i);
                            continue;
                        }
                    }
                }
            }
        }
        int len=st.size();
        return len;
    }
};