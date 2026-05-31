class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
       sort(items.begin(), items.end(),
     [](vector<int>& a, vector<int>& b){
         if(a[1] != b[1]){
             return a[1] < b[1];
         }
         return a[0] > b[0];
     });
     map<int,int>mpp;
     int maxi=INT_MIN;
     for(int i=0;i<n;i++){
        mpp[items[i][0]]++;
        maxi=max(maxi,items[i][0]);
     }
     vector<int>count(n,0);
     for(int i=0;i<n;i++){
         long long val=0;
         for(int j=items[i][0];j<=maxi;j+=items[i][0]){
            val+=mpp[j];
         }
         val--;
         count[i]=val;
     }
     long long ans=0;
     for(int i=0;i<n;i++){
        int z=budget/items[i][1];
        int mini=min(count[i],z);
        long long use=mini*items[i][1];
        int could=use/items[0][1];
        int maxi2=max(could,2*mini);
        if(maxi2!=could){
        budget-=use;
        ans+=(2*mini);
        }
     }
     ans+=(budget/items[0][1]);
     return ans;
    }
};