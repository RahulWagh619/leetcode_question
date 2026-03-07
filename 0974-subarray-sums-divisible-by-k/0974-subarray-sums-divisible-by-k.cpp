class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int v=sum;
            while(v<0){
                v+=k;
            }
            int val=v%k;
            ans+=mpp[val];
            mpp[val]++;
        }
        return ans;
    }
};