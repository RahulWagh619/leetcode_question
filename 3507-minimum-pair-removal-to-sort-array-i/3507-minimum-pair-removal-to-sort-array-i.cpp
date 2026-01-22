class Solution {
public:
bool desyn(vector<int>&nums){
    int n=nums.size();
    int ind=INT_MIN;
    int val=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=INT_MIN){
            ind=i;
            val=nums[i];
            break;
        }
    }

    for(int i=ind+1;i<n;i++){
        if(nums[i]!=INT_MIN){
            if(nums[i]>=val){
            val=nums[i];
            }
            else{
                return false;
            }
        }
    }
    return true;
}
bool helper(vector<int>nums,int mid){
       int n=nums.size();
          int count=0;
       while(count<=mid){
           int change=INT_MIN;
           int rem=INT_MIN;
           int mini=INT_MAX;
           int start=0;
           for(int i=0;i<n;i++){
             if(nums[i]!=INT_MIN){
                start=i;
                break;
             }
           }
          int ntbs=start;
           int ltbs=ntbs;
         for(int i=start+1;i<n;i++){
            if(nums[i]==INT_MIN)continue;
             int sum=nums[ntbs]+nums[i];
             if(mini>sum){
                mini=sum;
                change=ntbs;
                rem=i;
                ltbs=i;
             }
                ntbs=i;
         }
          bool z=desyn(nums);
           if(z){
            return true;
           }
         nums[rem]=mini;
         nums[change]=INT_MIN;
         count++;
       }
       return false;
}
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int ans=end;
        if(start==end){
            return 0;
        }
        while(start<=end){
              int mid=start+(end-start)/2;
              if(helper(nums,mid)){
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