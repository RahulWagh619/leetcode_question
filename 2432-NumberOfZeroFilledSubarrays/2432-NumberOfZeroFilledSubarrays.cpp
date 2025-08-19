// Last updated: 8/19/2025, 8:58:34 PM
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                if(count>0){
                    long long val=(count)*(count+1);
                    val/=2;
                    ans+=val;
                    count=0;
                }
            }
        }
        if(count>0){
                long long val=(count)*(count+1);
                    val/=2;
                    ans+=val;
        }
        return ans;
    }
};