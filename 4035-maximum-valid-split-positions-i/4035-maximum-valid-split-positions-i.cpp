class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>a;
        a.push_back(nums);
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                v.push_back(nums[j]);
            }
            a.push_back(v);
        }
        for(int i=0;i<a.size();i++){
            if(a[i].size()==1)continue;
            int size=a[i].size();
            vector<int>pf(size);
            vector<int>sf(size);
            pf[0]=a[i][0];
            sf[size-1]=a[i][size-1];
            for(int j=1;j<size;j++){
                pf[j]=__gcd(pf[j-1],a[i][j]);
            }
            for(int j=size-2;j>=0;j--){
                sf[j]=__gcd(sf[j+1],a[i][j]);
            }
            int count=0;
            for(int j=1;j<size;j++){
                if(pf[j-1]==sf[j]){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;

    }
};