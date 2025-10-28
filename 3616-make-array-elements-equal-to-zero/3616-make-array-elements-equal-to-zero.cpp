class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int>pf(nums.size(),0);
        int n=nums.size();
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=nums[i]+pf[i-1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(pf[i]==pf[n-1]-pf[i]){
                    count+=2;
                }
                if(pf[n-1]-pf[i]==pf[i]+1||pf[n-1]-pf[i]==pf[i]-1){
                    count++;
                }
            }
        }
        return count;
    }
};