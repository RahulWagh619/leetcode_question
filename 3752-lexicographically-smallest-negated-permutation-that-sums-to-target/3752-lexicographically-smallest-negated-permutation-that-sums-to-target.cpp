class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long val = (long long)n * (n + 1) / 2;
        vector<int>ans;
        if(target>val||target<-val){
             return ans;
        }
        if(abs(val-target)%2==1){
            return ans;
        }
        set<long long>st;
            long long start=val;
            long long cur=n;
            while(cur>=1){
                if(start-(2LL*cur)>=target){
                    st.insert(cur);
                    ans.push_back(-cur);
                    start-=2LL*cur;
                }
                if(start==target){
                    break;
                }
                cur--;
            }
            for(int i=1;i<=n;i++){
                if(st.find(i)==st.end()){
                    ans.push_back(i);
                }
            }
            sort(ans.begin(),ans.end());
        return ans;
    }
};