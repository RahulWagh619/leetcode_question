class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int level=n;level>1;level--){
            for(int i=0;i<level-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
    }
};