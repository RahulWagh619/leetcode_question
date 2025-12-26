class Solution {
public:
    int bestClosingTime(string customers) {
        int count=0;
        int n=customers.length();
        vector<int>sf(n);
        sf[n-1]=0;
        if(customers[n-1]=='Y'){
            sf[n-1]=1;
        }
        vector<int>pf(n+1);
        pf[0]=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                count++;
                pf[i+1]=pf[i]+1;
            }
            else{
                pf[i+1]=pf[i];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(customers[i]=='Y'){
                sf[i]=sf[i+1]+1;
            }
            else{
                sf[i]=sf[i+1];
            }
        }
        // for(int i=n-1;i>=0;i--){
        //     cout<<sf[i]<<" "<<i<<endl;
        // }
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            int val=sf[i]+pf[i];
            cout<<val<<" "<<i<<endl;
            ans.push_back({val,i});
        }
        ans.push_back({count,n});
        sort(ans.begin(),ans.end());
        int z=ans[0].second;
        return z;
    }
};