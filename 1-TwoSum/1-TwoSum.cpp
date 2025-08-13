// Last updated: 8/13/2025, 3:38:17 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            if(mpp.count(val)){
                ans.push_back(i);
                ans.push_back(mpp[val]);
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};