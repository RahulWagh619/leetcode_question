class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countone=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                countone++;
            }
        }
        if(countone==n){
            return n-1;
        }
        if(countone==0){
            return 0;
        }
        int maxi=1;
        int idx=0;
        int skip=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                skip++;
            }
            if(skip==2){
                maxi=max(maxi,i-idx-1);
                while(skip==2){
                    if(nums[idx]==0){
                        skip--;
                    }
                     idx++;
                }
            }
        }
            // if(i==n-1){
        maxi=max(maxi,n-1-idx);
            // }
        return maxi;
    }
};