class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int>ans;
        multiset<int>st;
        int n=a.size();
        for(int i=0;i<k;i++){
            st.insert(a[i]);
        }
        ans.push_back(*st.rbegin());
        for(int i=1;i<n-k+1;i++){
            st.erase(st.find(a[i-1]));
            st.insert(a[i+k-1]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};