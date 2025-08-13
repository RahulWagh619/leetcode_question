// Last updated: 8/13/2025, 3:33:35 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         long long maxi=0;
         long long n=nums.size();
        // long long k=n-1;
        // long long j=n-2;
        // long long i=n-3;
        // long long mini1=nums[j];
        // long long maxi1=nums[k];
        // while(i>=0){
        //     long long val=(nums[i]-mini1)*maxi1;
        //     i--;
        //     j--;
        //     k--;
        //     if(nums[j]<mini1){
        //              mini1=nums[j];
        //         if(nums[k]>maxi1){
        //             if(j<k){
        //                 maxi1=nums[k];
        //             }
        //         }
        //     }
        //     maxi=max(maxi,val);
        // }
        // return maxi;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    maxi=max(1ll*(nums[i]-nums[j])*nums[k],maxi);
                }
            }
        }
    return maxi;
    }
};