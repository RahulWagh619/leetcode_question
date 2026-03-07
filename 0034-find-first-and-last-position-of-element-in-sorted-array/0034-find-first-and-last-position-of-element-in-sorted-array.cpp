class Solution {
public:
// int helper(int start,int end,vector<int>& nums, int target){
//     while(start<=end){
//         int mid=start+(end-start)/2;
//         if(nums[mid]==target)return mid;
//         else if(nums[mid]>target){
//             end=mid-1;
//         }
//         else{
//             start=mid+1;
//         }
//     }
//     return -1;
// }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx=-1;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
        if(nums[mid]==target){
            idx=mid;
            break;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
         }
        } 
        vector<int>ans;
        if(idx==-1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }  
        int first=lower_bound(nums.begin(),nums.begin()+idx+1,target)-nums.begin();
        int second=upper_bound(nums.begin()+idx,nums.end(),target)-(nums.begin());
        second--;
        ans.push_back(first);
        ans.push_back(second);
        // ans.push_back({first,second});
            return ans;
    }
};