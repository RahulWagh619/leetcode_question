class Solution {
public:
bool check(vector<int>nums,int mid,int k){
    // bool ans=true;
    int sum=0;
    int i=0;
    for(int j=0;j<k;j++){
        if(i>=nums.size()){
            break;
        }
        while (i < nums.size() && sum + nums[i] <= mid) {
    sum += nums[i];
    i++;
}
        sum=0;
    }
    if(i>=nums.size())return true;
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int result = -1;
        int left=*min_element(nums.begin(),nums.end());
        int right=0;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(nums,mid,k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
       }
        return result;
    }
};