class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int i=0;
        int j=i+1;
        for(int k=2;k<nums.size();k++){
            if(nums[i]+nums[j]>nums[k]){
               maxi=max(maxi,nums[i]+nums[j]+nums[k]);
            }
            i++;
            j++;
        }
        return maxi;
    }
};