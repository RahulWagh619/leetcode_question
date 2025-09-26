class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    long long val1=nums[i];
                    long long val2=nums[j];
                    long long val3=nums[k];
                    if((val1+val2>val3 && val1+val3>val2) && val3+val2>val1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};