class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n);
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            string v=to_string(nums[i]);
            int sum=0;
    
            for(int j=0;j<v.length();j++){
                 sum+=(v[j]-'0');
            }
            a[i]=sum;
            mini=min(sum,mini);
        }
        return mini;
    }
};