class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        vector<int>nsr(n);
        vector<int>nsl(n);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=st.top().first){
                st.pop();
            }
            if(st.empty()){
                nsl[i]=-1;
            }
            else{
                nsl[i]=st.top().second;
            }

                st.push({heights[i],i});
        }
       while(!st.empty()) {
    st.pop();
}
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=st.top().first){
                st.pop();
            }
            if(st.empty()){
                nsr[i]=n;
            }
            else{
                nsr[i]=st.top().second;
            }
                st.push({heights[i],i});
         }
         for(int i=0;i<n;i++){
            int val=(nsr[i]-nsl[i]-1);
            int z=val*heights[i];
            maxi=max(maxi,z);
         }
         return maxi;
    }
};