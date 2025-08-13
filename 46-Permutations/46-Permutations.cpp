// Last updated: 8/13/2025, 3:37:34 PM
class Solution {
public:
void permutation(vector<int>&nums,int i,vector<vector<int>>&ans){
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        permutation(nums,i+1,ans);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        vector<vector<int>>ans;
        permutation(nums,i,ans);
    return ans;
    }
};