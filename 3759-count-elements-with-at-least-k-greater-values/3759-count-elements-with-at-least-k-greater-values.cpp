class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        long long count=0;
        long long n=nums.size();
        if(k==0){
            return n;
        }
        sort(nums.begin(),nums.end());
        for(long long i=0;i<n;i++){
            long long index=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            // cout<<nums[i]<<" "<<index<<endl;
            if(index<n){
                long long val=n-index;
                if(val>=k){
                    count++;
                }
            }
        }
        return count;
    }
};