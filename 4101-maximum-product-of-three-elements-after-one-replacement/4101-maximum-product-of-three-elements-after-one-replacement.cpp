class Solution {
public:
typedef long long ll;
    long long maxProduct(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
        nums[i]=abs(nums[i]);
       }
       sort(nums.rbegin(),nums.rend());
       return 1LL*nums[0]*1LL*nums[1]*1LL*100000;
    }
};