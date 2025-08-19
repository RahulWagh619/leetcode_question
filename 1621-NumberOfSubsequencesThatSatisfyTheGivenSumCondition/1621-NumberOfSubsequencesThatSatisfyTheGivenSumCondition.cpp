// Last updated: 8/19/2025, 8:58:48 PM
class Solution {
public:
int mod=1e9+7;
long long power(int a, int b, int mod)
{
    if (b == 0)
    {
        return 1;
    }
    long long  res = power(a, b / 2, mod);
    res = (res * res) % mod;
    if (b & 1)
    {
        res = (res * a) % mod;
    }
    return res;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]<nums[i]){
                break;
            }
            int idx=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-(nums.begin()+i);
            long long val=power(2,idx-1,mod);
            // val/=2;
            // val-=(idx-1);
            count=((count%mod)+(val%mod))%mod;
        }
        return count;
    }
};