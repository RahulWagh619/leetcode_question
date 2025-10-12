class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=2;
        int n=nums.size();
        int j=0;
        for(int i=2;i<n;i++){
            if(nums[i]!=nums[i-1]+nums[i-2]){
                 j=i-1;
            }
            else{
                ans=max(i-j+1,ans);
            }
        }
        return ans;
    }
};