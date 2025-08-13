// Last updated: 8/13/2025, 3:33:25 PM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int n=nums.size();
        long long count=n/3;
        for(int i=n-2;i>=0;i-=2){
            // cout<<nums[i]<<endl;
            sum+=nums[i];
            count--;
            if(count==0){
                break;
            }
        }
        return sum;
    }
};