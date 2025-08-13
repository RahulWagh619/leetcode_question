// Last updated: 8/13/2025, 3:34:39 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        int sum=0;
        map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count+=mpp[sum-goal];
            mpp[sum]++;
        }
        return count;
    }
};