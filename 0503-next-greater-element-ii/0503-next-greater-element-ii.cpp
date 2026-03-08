class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<pair<int,int>>st;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(st.empty()){
               st.push({nums[i],i});
            } 
            else{
               while(!st.empty() && nums[i]>st.top().first){
                   ans[st.top().second]=nums[i];
                   st.pop();           
               }
                st.push({nums[i],i});
            }
            q.push(nums[i]);
        }
        while(!st.empty()){
            int val=st.top().first;
            int idx=st.top().second;
            while(!q.empty()){
                if(q.front()>val){
                    ans[idx]=q.front();
                    break;
                }
                else{
                    q.pop();
                }
            }
            if(q.empty()){
                break;
            }
            st.pop();
        }
        return ans;
    }
};