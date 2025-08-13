// Last updated: 8/13/2025, 3:36:15 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int left=nums[i];
            if(i-2>=0){
            left+=prev2;
            }
            int right=prev;
            int curi=max(left,right);
            prev2=prev;
            prev=curi;
        }
        return prev;   
    }
};