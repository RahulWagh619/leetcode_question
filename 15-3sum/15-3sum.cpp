// Last updated: 8/13/2025, 3:38:07 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int j,k;
        for(int i=0;i<nums.size();i++){
            j=i+1;
            k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1])continue;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    vector<int>store={nums[i],nums[j],nums[k]}; 
                 ans.push_back(store);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};