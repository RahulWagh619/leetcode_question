// Last updated: 8/13/2025, 3:35:07 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count+=mpp[sum-k];
            mpp[sum]++;
        }
        return count;
        
    }
};