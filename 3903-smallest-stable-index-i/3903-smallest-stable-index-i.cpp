class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        // int idx=-1;
        vector<int>pf(n,0);
        vector<int>sf(n,0);
        pf[0]=nums[0];
        sf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pf[i]=max(pf[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            sf[i]=min(sf[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int val=pf[i]-sf[i];
            if(val<=k){
                return i;
            }
        }
        return -1;
    }
};