// Last updated: 8/13/2025, 3:35:53 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        // if(k==1){
        //     return a;
        // }
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<k;i++){
           while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
           }
           q.push_back(i);
        }
        ans.push_back(a[q.front()]);
        for(int i=k;i<a.size();i++){
            while(!q.empty() && i-k+1>q.front()){
                // ans.push_back(a[q.front()]);
                q.pop_front();
            }
            while(!q.empty() && a[i]>=a[q.back()]){
            q.pop_back();
           }
           q.push_back(i);
           ans.push_back(a[q.front()]);
        }
        return ans;
    }
};