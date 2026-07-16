class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>a;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           maxi=max(maxi,nums[i]);
           int val=__gcd(nums[i],maxi);
           a.push_back(val);
        }
        sort(a.begin(),a.end());
        long long sum=0;
        int size=a.size();
        for(int i=0;i<size/2;i++){
            int val=__gcd(a[i],a[size-i-1]);
            // cout<<val<<
            sum+=val;
        }
        return sum;
    }
};