// Last updated: 8/13/2025, 3:35:28 PM
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[j-1]==diff){
                    count++;
                }
                else{
                    break;
                }
                if(count>=2){
                    total++;
                }
            }
        }
        return total;
    }
};