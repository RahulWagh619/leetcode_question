// Last updated: 8/13/2025, 3:34:36 PM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            if (sum < 0)
                sum = sum + k;
            count+=mpp[sum];
            mpp[sum]++;
        }
        return count;
        
    }
};