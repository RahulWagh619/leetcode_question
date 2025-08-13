// Last updated: 8/13/2025, 3:35:16 PM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.find(sum%k)!=mpp.end()){
               if(i-mpp[sum%k]>=2)return true;
            }
            else{
                mpp[sum%k]=i;
            }
        }
        return false;
        
    }
};