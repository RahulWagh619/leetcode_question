// Last updated: 8/13/2025, 3:35:55 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int>ans;
         int n=nums.size();
         vector<int>pf(n);
         pf[0]=1;
         for(int i=1;i<n;i++){
            pf[i]=pf[i-1]*nums[i-1];
         }
         vector<int>sf(n);
         sf[n-1]=1;
         for(int i=n-2;i>=0;i--){
            sf[i]=sf[i+1]*nums[i+1];
         }
         for(int i=0;i<n;i++){
            ans.push_back(pf[i]*sf[i]);
         }

         return ans;
        
    }
};