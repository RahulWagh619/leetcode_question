class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxi=INT_MIN;;
        int cmaxi=nums[0];
        int n=nums.size();
        for(int i=k;i<n;i++){
           cmaxi=max(cmaxi,nums[i-k]);
           maxi=max(maxi,cmaxi+nums[i]);
        }
        return maxi;
    }
};