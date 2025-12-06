class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique2.size();
        set<int>st;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            int val=technique1[i]-technique2[i];
            vp.push_back({val,i});
        }
        sort(vp.rbegin(),vp.rend());
        long long sum=0;
        int i=0;
        while(k>0){
           int index=vp[i].second;
           sum+=technique1[index];
           st.insert(index);
           i++;
           k--;
        }
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()){
                sum+=max(technique1[i],technique2[i]);
            }
        }
        return sum;
    }
};