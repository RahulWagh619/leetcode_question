// Last updated: 8/13/2025, 3:35:15 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count1=0;
        int count0=0;
        int ans=0;
        map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count1++;
            }
            else count0++;
            int diff=count1-count0;
            if(mpp.count(diff)){
                ans=max(ans,i-mpp[diff]);
            }
            else{
                mpp[diff]=i;
            }
        }
        return ans;
        
    }
};