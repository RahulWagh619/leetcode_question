// Last updated: 8/13/2025, 3:34:15 PM
class Solution {
public:
int val(int mid,vector<int>&nums){
    int sum1=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%mid==0){
            sum1+=nums[i]/mid;
        }
        else{
         int k=(nums[i]+mid-1);
         k/=mid;
         sum1+=k;
        }
      
    }
    return sum1;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            int diff=val(mid,nums);
            // cout<<mid<<" "<<diff<<endl;
            if(diff<=threshold){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            } 
        }
        return ans;
    }
};