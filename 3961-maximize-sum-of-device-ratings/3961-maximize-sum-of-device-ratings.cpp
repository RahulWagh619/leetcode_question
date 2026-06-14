class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        for(auto &row:units){
            sort(row.begin(),row.end());
        }
        int n=units.size();
        // vector<int>diff(n);
        long long sum=0;
        if(units[0].size()==1){
            for(int i=0;i<n;i++){
                sum+=units[i][0];
            }
            return sum;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=units[i][1];
            mini=min(mini,units[i][0]);
            // diff[i]=units[i][1]-units[i][0];
        }
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long cur=sum-units[i][1]+mini;
            ans=max(ans,cur);
        }
        return ans;
        

    }
};